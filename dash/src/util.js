const { execSync } = require('child_process');
const { join, dirname } = require('path');
const checkDebug = (pr1, pr2, pr3) => {
    return pr1 || pr2 || pr3
}

const execCMD = (cmd, ops) => {
    // --no-sentry disables prompts
    const flags = `--no-sentry ${ops.debug ? '--debug' : ''} ${ops.verbose ? '--verbose' : ''}`
    const out = execSync(`pros ${flags} ${cmd}`, { cwd: ops.cwd || __dirname }).toString()
    
    return out;
}
const getProjectPath = () => {
    return process.env.PROJECT_PATH || join(__dirname,'../..', 'project')
}

module.exports = {
    execCMD, 
    checkDebug,
    getProjectPath
}