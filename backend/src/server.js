const express = require('express');
const cors = require('cors');
const app = express();
const port = 3000;

const corsOptions = {
  origin: 'http://localhost:5173', // frontend origin
  optionsSuccessStatus: 200
};

// Use the CORS middleware with options
app.use(cors(corsOptions));
app.use(express.json()); // Middleware to parse JSON bodies

app.get('/', (req, res) => {
  res.send('Hello World!');
});

app.get('/programmingLanguage', (req, res) => {
  const data = [
    { language: 'JavaScript', percentage: 69.8 },
    { language: 'Python', percentage: 44.1 },
    { language: 'Java', percentage: 40.2 },
    { language: 'C#', percentage: 31.1 },
    { language: 'PHP', percentage: 26.2 }
  ];
  res.json(data);
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
