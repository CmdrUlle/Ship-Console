/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: benny
 *
 * Created on 10. März 2016, 08:54
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string> 
#include <sstream>
#include <cctype> // std::tolower
#include <stdlib.h>
#include <math.h>
#include <random>
#include <time.h>
#include <fstream>
#include <stdlib.h>


int phase = 0;
void getSystemInfo(std::string inputstring);

void gibberish(int length) {
    int randInt = 0;
    //    int randInt = rand() % 20 + 20;
    for (int i = 0; i < length; i++) {
        randInt = std::rand() % 96;
        std::cout << (char) (' ' + randInt);
        if ((rand() % 100) < 2) std::cout << std::endl;
    }
    std::cout << std::endl;
}

void gibberish2() {
    std::cout << "\n4c616e677561676520636f7265206661696c696e672e\n52657374617274696e67204c616e677561676520436f72652e\n" << std::endl;
}

void helloStrings(int length) {
    for (int i = 0; i < length; i++) {
        //        randInt = std::rand() % 96;
        std::cout << "hello  ";
        if ((rand() % 100) < 2) std::cout << std::endl;
    }
}

void writeTimes(std::string input, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << input;
    }
    std::cout << std::endl;
}

void littleHelperPhase2();

void checkInput(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    std::cout << " " << input << std::endl;
    bool recog = false;
    if (input.find("hello") != std::string::npos || input.find("hello") != std::string::npos || input.find("hi") != std::string::npos) {
        helloStrings(400);
        recog = true;
    }
    if (input.find("who is") != std::string::npos || input.find("who are") != std::string::npos || input.find("what are") != std::string::npos || (input.find("are") != std::string::npos && (input.find("ki") != std::string::npos || input.find("ai") != std::string::npos))) {
        std::cout << " ~~~~~~~~~~~\n~~~\n~~\n~~~  ***\n ~~~*****~~~\n     ***  ~~~\n           ~~\n          ~~~\n ~~~~~~~~~~~\n Karak Orthos\n OMLY-AUG-2391\n" << std::endl;
        recog = true;
    }
    if (input.find("what happend") != std::string::npos || input.find("alien") != std::string::npos) {
        std::cout << "Montalaar" << std::endl;
        recog = true;
    }
	if (input.find("administrator") != std::string::npos || input.find("admin") != std::string::npos) {
        std::cout << "Service currently unavailable. Try system info" << std::endl;
        recog = true;
    }
    if (input.find("where are you from") != std::string::npos) {
        std::cout << "Omicron Lyrae" << std::endl;
        recog = true;
    }
    if (input.find("where are they") != std::string::npos) {
        std::cout << "Montalaar" << std::endl;
        recog = true;
    }
    if (input.find("montalaar") != std::string::npos) {
        std::cout << "Enemies" << std::endl;
        recog = true;
    }
    if (input.find("where is it?") != std::string::npos) {
        std::cout << "Specify!" << std::endl;
        recog = true;
    }
    if (input.find("where is montalaar?") != std::string::npos) {
        writeTimes("error", 10);
        std::cout << "Error: Montalaar could not be resolved. \n Error: Could not find database \' Map ' \n Error: System not running" << std::endl;
        recog = true;
    }
    if (input.find("wo ist omicron?") != std::string::npos) {
        writeTimes("error", 10);
        std::cout << "Error: Omicron Lyrae could not be resolved. \n Error: Could not find database \' Map ' \n Error: System not running" << std::endl;
        recog = true;
    }
    if (input.find("where is karak orthos?") != std::string::npos) {
        std::cout << "Sektor 0x0" << std::endl;
        recog = true;
    }
    if (input.find("omly-aug-2391") != std::string::npos) {
        std::cout << "Registry number: OMLY-AUG-2391" << std::endl;
        recog = true;
    }
    if (phase == 0 && input.find("system") != std::string::npos) {
        std::cout << "Error: System diagnosis not available" << std::endl;
        recog = true;
    }
    if (phase > 0) {
        if (input.find("permission") != std::string::npos || input.find("system") != std::string::npos || input.find("bridge") != std::string::npos || input.find("terminal") != std::string::npos || input.find("access") != std::string::npos) {
            std::cout << "Rebooting systems" << std::endl;
            recog = true;
        }
    }

    if (phase > 1) {
        if (input.find("omly-aug-2391") != std::string::npos) {
            std::cout << "Registry number: OMLY-AUG-2391" << std::endl;
            recog = true;
        }
        if (input.find("system info") != std::string::npos) {
            littleHelperPhase2();
            recog = true;
        } else if (input.find("system") != std::string::npos) {
            getSystemInfo(input);
            recog = true;
        }
    }

    if (recog == false) {
        std::cout << std::endl;
        gibberish(rand() % 50 + 10);
        std::cout << std::endl;
    }

    //    if (input.find("")) {

    //    }
}

void getSystemInfo(std::string inputstring) {
    std::vector<std::string> systems1 = {"air control", "door control", "fusion reactor control", "spike drive control", "navigation system", "weapon control", "airlock protocol", "airlock security protocol", "expert system Control", "Water control",  "computer control", "light control", "hydroponics", "engineering", "shuttle bay door control", "shuttle bay maintenace programm", "messenger system protocol", "sensor array", "factory control", "waste control",};
    //    std::vector<std::string> systems1 = {"Air Control", "Door Control", "Fusion reactor Control", "Spike Drive Control", "Navigation system", "Weapon control", "Airlock Protocol", "Airlock Security Protocol", "Expert System Control", "Water control", "Light Control", "Hydroponics", "Engineering", "Shuttle Bay Door Control", "Shuttle Bay Maintenace Programm", "Messenger System Protocol", "Sensor Array", "Factory Control", "Waste Control",};
    for (std::string system : systems1) {
        if (inputstring.find(system) != std::string::npos) {
            std::cout << system << " error. Can't connect to system" << std::endl;
        }
    }
    if (inputstring.find("Air Control") != std::string::npos) {
        std::cout << system << " error. Unknown substance in tanks. Do you want to override main control valve? [y/n]" << std::endl;
        std::string temp;
        std::getline(std::cin, temp);
    }
    if (inputstring.find("navigation system") != std::string::npos) {
        std::cout << system << " error. Database deleted or moved." << std::endl;
    }

    if (inputstring.find("sensor array") != std::string::npos) {
        std::cout << "System functional. Do a quick system scan? [y/n]" << std::endl;
        std::string temp;
        bool doMe = false;
        std::getline(std::cin, temp);
        if (temp.compare("y") == 0) {
            doMe = true;
        } else if (temp.compare("n") == 0) {

        } else {
            std::cout << "[y/n]" << std::endl;
            std::getline(std::cin, temp);
            if (temp.compare("y") == 0) {
                doMe = true;
            }
        }
        if (doMe == true) {
            std::cout << "\n\n* Scanning..." << std::endl;
            std::cout << "* ***********" << std::endl;
            std::cout << "" << std::endl;
        }
    }


}

void createPhase1() {
    std::vector<std::string> systems = {"Air Control", "Door Control", "Fusion reactor Control", "Spike Drive Control", "Navigation system", "Weapon control", "Airlock Protocol", "Airlock Security Protocol", "Expert System Control", "Computer Control", "Water control", "Light Control", "Hydroponics", "Engineering", "Shuttle Bay Door Control", "Shuttle Bay Maintenace Programm", "Messenger System Protocol", "Sensor Array", "Factory Control", "Waste Control",};
    for (std::string system : systems) {
        std::cout << "** Loading " << system << ":: Failed" << std::endl;
    }
    std::cout << "* Initialize graphical user interface:: Failed" << std::endl;
    std::cout << "* Initialize bonjour service:: Failed" << std::endl;

    std::cout << "ERROR: FATAL ERROR: Multiple Errors. Please report back to system administrator" << std::endl;
}

void littleHelperPhase2() {
    std::vector<std::string> systems = {"\n\nAir Control:: Failed", "Door Control:: Success", "Fusion reactor Control:: Failed", "Spike Drive Control:: Failed", "Navigation system:: Failed", "Weapon control:: Failed", "Airlock Protocol:: Success", "Airlock Security Protocol:: Failed", "Expert System Control:: Failed", "Computer Control:: Failed", "Water control:: Failed", "Light Control:: Success", "Hydroponics:: Failed", "Engineering:: Failed", "Shuttle Bay Door Control:: Success", "Shuttle Bay Maintenace Programm:: Failed", "Messenger System Protocol:: Success", "Sensor Array:: Success", "Factory Control:: Failed", "Waste Control:: Failed",};
    int counter = 0;
    for (std::string system : systems) {
        std::cout << "** Loading " << counter++ << ": " << system << std::endl;
    }
}

void createPhase2() {
    littleHelperPhase2();
    std::cout << "* Initialize graphical user interface:: Failed" << std::endl;
    std::cout << "* Initialize bonjour service:: Failed" << std::endl;

    std::cout << "ERROR: FATAL ERROR: Multiple Errors. Please report back to system administrator" << std::endl;

    std::cout << "System diagnose available: Type 'system info' or 'system ''name'" << std::endl;
}

int main(int argc, char** argv) {
	gibberish(100);
	
	for(int i = 1; i < 5; i++)	{
		std::string temp;
		std::getline(std::cin, temp);
		checkInput(temp);
	}
	createPhase1();
	phase = 1;
	
	for(int i = 1; i < 5; i++)	{
		std::string temp;
		std::getline(std::cin, temp);
		checkInput(temp);
	}
	
	createPhase2();
	phase = 2;
	
	std::string temp;
	std::getline(std::cin, temp);
	checkInput(temp);
	
	
	std::cout << "..." << std::endl;
	
	
	
	std::cout << "Now the GM takes over..." << std::endl; 
	
	system("pause");
	exit(0);
}