
#include "AutoBuilder.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

AutoBuilder::AutoBuilder(const std::string &filename) 
{
  wpi::SmallVector<char, 50> deployDirectoryVector;
  frc::filesystem::GetDeployDirectory(deployDirectoryVector);
  std::string deployDirectory;
  deployDirectory.append(deployDirectoryVector.begin(),
                         deployDirectoryVector.end());
  std::string completeFilename = deployDirectory + "/" + filename;
  std::ifstream file;
  file.open(completeFilename);
  if (!file.is_open()) 
	{
    std::cerr << completeFilename << " failed to open" << std::endl;
    return;
  }
  std::string line;
  while (getline(file, line)) 
	{
		if(auto func = ParseLine(line)) 
		{
			m_functions.push_back(func.value());
		}
  }
}

void ltrim(std::string &s) 
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  [](int ch) { return !std::isspace(ch); }));
}

void rtrim(std::string &s) 
{
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](int ch) { return !std::isspace(ch); })
              .base(),
          s.end());
}

void trim(std::string &s) 
{
  ltrim(s);
  rtrim(s);
}

std::vector<std::string> split(const std::string &s, char del) 
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream stream{s};
  while (std::getline(stream, token, del)) {
    tokens.push_back(token);
  }
  return tokens;
}

std::optional<AutoBuilder::Function>
AutoBuilder::ParseLine(const std::string &line)
{
  Function func;
	if(line.find('(') == std::string::npos) return std::nullopt;
  std::string name = line.substr(0, line.find('('));
  trim(name);
	if(name.length() == 0) return std::nullopt;
  func.name = name;
	if(line.find(')') == std::string::npos) return std::nullopt;
  std::string argsstr =
      line.substr(line.find('(') + 1, line.find(')') - (line.find('(') + 1));
  func.args = split(argsstr, ',');
  std::for_each(func.args.begin(), func.args.end(),
                [](std::string &s) { trim(s); });
  return func;
}
