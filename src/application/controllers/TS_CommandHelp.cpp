/**
 * TS-CommandHelp
 *
 * Help command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>

#include "TS_IModel.h"
#include "TS_Command.h"
#include "TS_CommandHelp.h"

/**
 * @inherit
 */
TS_CommandHelp::TS_CommandHelp(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{}

/**
 * @inherit
 */
bool TS_CommandHelp::execute()
{
    this->prepare();
    return true;
}

/**
 * @inherit
 */
bool TS_CommandHelp::prepare()
{
    return true;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandHelp::getMessage()
{
    std::ostringstream message;
    message << "Available commands:" << std::endl;
    message << "- help:" << "\t\t" << "Show's the help menu" << std::endl;
    message << "- config:" << "\t" << "Show's the config options" << std::endl;
    message << "- projects:" << "\t" << "List all available projects" << std::endl;
    message << "- times:" << "\t" << "List all tracked times of selected project" << std::endl;
    message << "- touch <name>:" << "\t" << "Create's a new project" << std::endl;
    message << "- rm <name>:" << "\t" << "Delete's entered project" << std::endl;
    message << "- use <name>:" << "\t" << "Set project to track time on, a name from 'list' command" << std::endl;
    message << "- start:" << "\t" << "Start's timetracking" << std::endl;
    message << "- stop:" << "\t\t" << "Stop's timetracking" << std::endl;
    message << "- save:" << "\t\t" << "Save new timetrack depending on settings" << std::endl;
    message << "- export <p>:" << "\t" << "Export selected project to given path (selected by 'use' command)";

    return message;
}
