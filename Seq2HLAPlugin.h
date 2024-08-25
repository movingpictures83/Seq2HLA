#ifndef Seq2HLAPLUGIN_H
#define Seq2HLAPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class Seq2HLAPlugin : public Plugin
{
public: 
 std::string toString() {return "Seq2HLA";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
