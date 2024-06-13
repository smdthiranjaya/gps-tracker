const express = require('express');
const app = express();
const port = process.env.PORT || 8080;

// Middleware to log incoming requests
app.use((req, res, next) => {
  console.log(`Received ${req.method} request from: ${req.ip}`);
  console.log('Query parameters:', req.query);
  next();
});

// Route to handle GET requests
app.get('/get', (req, res) => {
  // Log the latitude and longitude parameters
  const lat = req.query.lat;
  const lon = req.query.lon;

  if (lat && lon) {
    console.log(`Latitude: ${lat}`);
    console.log(`Longitude: ${lon}`);
  } else {
    console.log('Latitude and/or Longitude parameters are missing');
  }

  res.send('Data received');
});

app.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});
