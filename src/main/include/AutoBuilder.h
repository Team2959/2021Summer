#pragma once

#include <vector>
#include <string>
#include <frc/Filesystem.h>
#include <utility>
#include <optional>
#include <list>

class AutoBuilder
{
public:
	AutoBuilder(const std::string& filename = "auto.txt");
private:
	struct Function
	{
		std::string name;
		std::vector<std::string> args;
	};
	std::list<Function> m_functions;
	std::optional<Function> ParseLine(const std::string& line);
};
