#pragma once
#include "Command.h"

class JumpCommand final : public Command
{
public:
	void Execute() override;
};

