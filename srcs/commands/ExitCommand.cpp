/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:05:54 by tglory            #+#    #+#             */
/*   Updated: 2022/05/28 17:47:38 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/ExitCommand.hpp"

namespace ft {

	ExitCommand::ExitCommand() : ClientCommand("EXIT", 0, "\\!/ Kill the server", "", true, true, true) {}

	ExitCommand::~ExitCommand() {}

	bool ExitCommand::execute(CommandContext &cmd) const {
		ServerIRC *server = cmd.getServer();
		ClientIRC *client = cmd.getClient();
		
		client->recieveMessage("006 " + client->getNick() + " Bye bye !");
		server->stop();
		return true;
	}
}
