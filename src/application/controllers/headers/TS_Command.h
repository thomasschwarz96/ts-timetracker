/**
 * TS-Command
 *
 * Abstract superclass for all commands
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMAND_H
#define TS_TIMETRACKER_TS_COMMAND_H

#include <sstream>
#include "TS_IModel.h"

class TS_Command
{
public:
    explicit TS_Command(char *arguments, TS_IModel* model);
    ~TS_Command() = default;
    void setTestMode(bool testMode);
    virtual bool execute();
    virtual std::ostringstream getMessage();

protected:
    virtual bool prepare();
    char *arguments;
    TS_IModel* model;
    bool isTestMode;
};


#endif //TS_TIMETRACKER_TS_COMMAND_H
