const express = require('express');
const app = express();
const port = 3000;
const path = require('path');
const c = require('child_process')
const fs = require('fs')
const morgan = require('morgan');
const { getProjectPath } = require('./util');
const checkPros = () => {
    try {
       c.execSync('pros');
    } catch (e) {
        console.log(
            new Array(10).fill(0).map(() => ' ').join('') 
        );
console.log('\nNO PROS INSTALLED\n')

        console.log(
            new Array(10).fill(0).map(() => ' ').join('') 
        );
        process.exit(1)
   }
}
checkPros()
console.log(`Using project path: ${getProjectPath()}`)
app.use(morgan('dev'));
app.use(express.static('public'));
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
app.use('/api', require('./routes/api'));
app.get('/', (req, res) => res.render('index'));
app.listen(port, () => console.log(`Example app listening on port ${port}!`));
