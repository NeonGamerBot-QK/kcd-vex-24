
// Path: dash/src/t_/read_brain_data.js
// Compare this snippet from dash/src/index.js:
const rawData = (execSync('pros lsusb').toString().split('\n').filter(Boolean));
if (rawData.every(e => e.includes('There are no connected'))) {
    console.log('No brains found');
    process.exit();
}

console.log(rawData)



