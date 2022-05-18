/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:31:41 by tglory            #+#    #+#             */
/*   Updated: 2022/05/18 21:30:58 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/NickCommand.hpp"

namespace ft {

	NickCommand::NickCommand() : ClientCommand("NICK") {}

	NickCommand::~NickCommand() {}

	bool NickCommand::execute(CommandContext &cmd) const {
		ClientIRC *client = cmd.getClient();
		ServerIRC *server = cmd.getServer();
		std::vector<std::string> args = cmd.getArgs();
		std::string arg;

		if (args.empty()) {
			std::cout << C_YELLOW << *client << " try to set a empty Nickname." << C_RESET << std::endl;
			return false;
		}
		arg = cmd.getArg(0);
		client->setNick(arg);
		std::cout << C_YELLOW << "Nick of " << *client << " is now '" << arg << "'." << C_RESET << std::endl;
		client->recieveMessage(RPL_NICK(std::string(arg)));
		return true;
	}

}
