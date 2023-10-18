const { execCMD, checkDebug, getProjectPath } = require('../util');

const router = require('express').Router();
router.get('/brains', (req, res) => {
    const rawData = (execCMD('lsusb', {
        debug: checkDebug(req.query.debug, process.env.DEBUG, false), 
        verbose: checkDebug(req.query.verbose, process.env.DEBUG, false),
    }).split('\n').filter(Boolean));
if (rawData.every(e => e.includes('There are no connected'))) {
    res.send('No brains found');
    // process.exit();
    return;
}

res.send(rawData.join('\n'))
})

router.post('/upload', (req, res) => {
    try {
        const rawData = (execCMD('upload', {
            debug: checkDebug(req.query.debug, process.env.DEBUG, false), 
            verbose: checkDebug(req.query.verbose, process.env.DEBUG, false),
            cwd: getProjectPath()
        }));
        res.send(rawData)
    } catch (e) {
        res.status(500).send(e.output.map(e => e ? e.toString() : '').join('\n'))
  }
})
router.post('/make', (req, res) => {
    try {
        const rawData = (execCMD('make', {
            debug: checkDebug(req.query.debug, process.env.DEBUG, false), 
            verbose: checkDebug(req.query.verbose, process.env.DEBUG, false),
            cwd: getProjectPath()
        }));
        res.send(rawData)
    } catch (e) {
        res.status(500).send(e.output.map(e => e ? e.toString() : '').join('\n'))
  }
})
router.post('/upload_build', (req, res) => {
    try {
        const rawData = (execCMD('make', {
            debug: checkDebug(req.query.debug, process.env.DEBUG, false), 
            verbose: checkDebug(req.query.verbose, process.env.DEBUG, false),
            cwd: getProjectPath()
        }));
        const rawData2 = (execCMD('upload', {
            debug: checkDebug(req.query.debug, process.env.DEBUG, false), 
            verbose: checkDebug(req.query.verbose, process.env.DEBUG, false),
            cwd: getProjectPath()
        }));
        res.send(rawData + '\n' + rawData2)
    } catch (e) {
        res.status(500).send(e.output.map(e => e ? e.toString() : '').join('\n'))
  }
})
module.exports = router;