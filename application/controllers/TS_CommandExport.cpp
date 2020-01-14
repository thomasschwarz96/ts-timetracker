/**
 * TS-CommandExport
 *
 * Export command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <string>
#include <fstream>

#include "TS_Helper.h"
#include "TS_Command.h"
#include "TS_CommandExport.h"

/**
 * @inherit
 */
TS_CommandExport::TS_CommandExport(char *arguments) : TS_Command(arguments)
{
    this->successfulExport = false;
    this->exportPath = "";
    this->selectedProjectPath = "";
}

/**
 * @inherit
 */
bool TS_CommandExport::execute()
{
    this->prepare();

    if (this->exportPath.length() <= 0)
    {
        return false;
    }

    std::ifstream projectFile(this->selectedProjectPath, std::ios::binary);
    std::ofstream exportFile(this->exportPath, std::ios::binary);

    exportFile << this->createCsvHeadline() << std::endl;
    std::string line;
    while (std::getline(projectFile, line))
    {
        exportFile << this->convertLineForExport(line);
    }

    projectFile.close();
    exportFile.close();

    this->successfulExport = true;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandExport::prepare()
{
    this->exportPath = this->getExportPath();
    this->selectedProjectPath = this->getSelectedProjectPath();

    return true;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandExport::getMessage()
{
    std::ostringstream message;

    if (this->successfulExport)
    {
        message << "Exported '" << TS_Helper::getSelectedProjectName() << "' successfully to: ";
        message << this->exportPath;
    }
    else
    {
        message << "Error during export!" << std::endl;
        message << "Please try again.";
    }

    return message;
}

/**
 * Create headline for exported CSV file
 * @return  std::string
 */
std::string TS_CommandExport::createCsvHeadline()
{
    return "Start time;End time; Comment";
}

/**
 * Create export path
 * @return  std::string
 */
std::string TS_CommandExport::getExportPath()
{
    std::ostringstream path;

    if (this->arguments == nullptr)
    {
        path << TS_Helper::getProjectsPath();
    }
    else
    {
        path << this->arguments;
    }
    path << TS_Helper::getSelectedProjectName() << ".csv";

    return path.str();
}

/**
 * Get path of selected project path
 * @return  std::string
 */
std::string TS_CommandExport::getSelectedProjectPath()
{
    std::ostringstream projectToExport;
    projectToExport << TS_Helper::getProjectsPath();
    projectToExport << TS_Helper::getSelectedProjectName();

    return projectToExport.str();
}

/**
 * Converts given line for export
 * @param   std::string line
 * @return  std::string
 */
std::string TS_CommandExport::convertLineForExport(std::string line)
{
    unsigned counter = 0;
    char delimiter = ';';
    std::stringstream lineStream(line);
    std::stringstream preparedLine;

    while (std::getline(lineStream, line, delimiter))
    {
        if (counter < 2)
        {
            std::time_t timestamp = std::stoi(line);
            preparedLine << TS_Helper::formatTimestamp(timestamp) << ";";
            counter++;
        }
        else
        {
            preparedLine << line << std::endl;
            counter = 0;
        }
    }

    return preparedLine.str();
}
