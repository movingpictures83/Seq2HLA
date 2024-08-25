#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Seq2HLAPlugin.h"

void Seq2HLAPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void Seq2HLAPlugin::run() {
   
}

void Seq2HLAPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; python2 plugins/Seq2HLA/seq2HLA/seq2HLA.py ";
// python2 seq2HLA.py -1 /biorg/data/RNA/UMiami/small/S12_R1.fastq -2 /biorg/data/RNA/UMiami/small/S12_R2.fastq -r "Trevor"

 command += " -1 "+PluginManager::addPrefix(parameters["seq1"]);
 command += " -2 "+PluginManager::addPrefix(parameters["seq2"]);
 command += " -r "+file;
 //; export PYTHONPATH=OLDPATH"; 
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<Seq2HLAPlugin> Seq2HLAPluginProxy = PluginProxy<Seq2HLAPlugin>("Seq2HLA", PluginManager::getInstance());
