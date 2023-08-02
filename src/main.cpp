/*
 * File: main.cpp
 * Author: Sean Gallogly
 * Created on: circa 07/21/2022
 * 
 * Description:
 *     this is the main entry point to the program. It calls functions from commandline.h
 *     in order to parse arguments and from control.h in order to run the simulation
 *     in one of several user-specified modes.
 */
#include <time.h>
#include <iostream>
#include <fstream>
#include <omp.h>
#include <iomanip>

#include "control.h"
#include "gui.h"
#include "commandline.h"
#include "file_parse.h"
#include "logger.h"

int main(int argc, char **argv) 
{
	logger_initConsoleLogger(stderr);
// for now, set the log level dependent on whether
// we are compiling for debug target or release target
#ifdef DEBUG
	logger_setLevel(LogLevel_DEBUG);
#else
	logger_setLevel(LogLevel_DEBUG);
#endif
	parsed_commandline p_cl = {};
	parse_and_validate_parsed_commandline(&argc, &argv, p_cl);

	Control *control = new Control(p_cl);
	int exit_status = 0;

	omp_set_num_threads(1); /* for 4 gpus, 8 is the sweet spot. Unsure for 2. */

	if (p_cl.vis_mode == "TUI")
	{
		if (!p_cl.build_file.empty())
		{
			control->build_sim();
			control->save_sim_to_file();
		}
		else if (!p_cl.session_file.empty())
		{
			control->runSession(NULL); // saving is done at the end of runSession.
									   // might consider moving to own function and calling
									   // from here
		}
	}
	else if (p_cl.vis_mode == "GUI")
	{
		exit_status = gui_init_and_run(&argc, &argv, control);
	}
	delete control;
	return exit_status;
}

