# Nature Connection Program

# Part 1: Libraries

#Load the necessary libraries
library(tidyverse)
library(geojsonio)
library(rgdal)
library(raster)
library(leaflet)
library(magrittr)
library(htmltools)

# Part 2: Read in Shapefile and Geojson

# Read in the shapefile of nature reserves
nature_reserves <- readOGR(dsn = 'data/nature_reserves.shp')

# Read in the geojson of counties
counties <- geojson_read('data/counties.geojson', what = 'sp') 

# Part 3: Add Nature Reserves Layer to Map

# Initialize the leaflet map with the county geojson as the base layer
my_map <- leaflet() %>% 
  addPolygons(data = counties, weight = 1,
              fillColor = '#00FF00', fillOpacity = 0.2,
              color = '#000000', popup = counties@data$NAME_1)

# Add nature reserve layer as an overlay
my_map <- my_map %>% 
  addPolygons(data = nature_reserves, weight = 2, 
              fillColor = '#FFFFFF', fillOpacity = 0.4,
              color = '#0000FF', popup = nature_reserves@data$NAME)

# Part 4: Add Legend

# Create the legend for the nature reserves layer
nature_legend <- mapply(function(col, name) {
  mapply(function(fill, label, col) {
    colorBar(fill = fill,
             label = label,
             col = col)
  }, 
  fill = c('#FFFFFF', '#0000FF'),
  label = c('Nature Reserves', 'None'),
  col = col,
  SIMPLIFY = F
  )}, 
  col = c('#FFFFFF', '#0000FF'), 
  name = c('Nature Reserves', 'None')
)

# Add the legend to the map
my_map <- my_map %>%
  addLegend(position = "bottomright",
        colors = c('#FFFFFF', '#0000FF'),
        labels = c('Nature Reserves', 'None'),
        title = 'Nature Reserves',
        opacity = 1,
        layerId = 'nature_reserves_legend',
        legend = nature_legend
  )

# Part 5: Add Popup

# Create a popup for each nature reserve layer
nature_reserves_popup <- mapply(function(name, description) {
  mapply(function(name, description) {
    tags$div(
      tags$h3(name, style = 'color: #0000FF; font-size: 15px;'),
      tags$p(description, style = 'margin-left: 8px; font-size: 13px;')
    )
  }, 
  name = name,
  description = description,
  SIMPLIFY = F)
}, 
name = nature_reserves@data$NAME, 
description = nature_reserves@data$DESCRIPTIO)

# Add the popup to the map
my_map <- my_map %>%
  addPopups(data = nature_reserves,
        lat = ~Y, lng = ~X,
        popup = nature_reserves_popup
  )

# Part 6: Save Map

# Save the leaflet map
saveWidget(my_map, 'nature_connection_map.html')