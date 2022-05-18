/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:35:09 by tglory            #+#    #+#             */
/*   Updated: 2022/05/18 21:08:08 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/PartCommand.hpp"

namespace ft {

	PartCommand::PartCommand() : ClientCommand("PART") {}

	PartCommand::~PartCommand() {}

	bool PartCommand::execute(CommandContext &cmd) const {
		ClientIRC *client = cmd.getClient();
		ServerIRC *server = cmd.getServer();
		std::vector<std::string> args = cmd.getArgs();
		std::vector<std::string> channels;

		if (args.empty()) {
			client->recieveMessage(ERR_NEEDMOREPARAMS(this->name));
			return false;
		}
		channels = split(args[0], ",");
		for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it) {
			std::cout << C_BLUE << "Client " << *client << " want to PART channel '" << *it << "'" << C_RESET << std::endl;

			ChannelIRC *channel = server->getChannel(*it);
			if (!channel) {
				client->recieveMessage(ERR_NOSUCHCHANNEL(*it));
				continue;
			}
			if (!ft::clientExists(client, channel->getClientList())) {
				client->recieveMessage(ERR_NOTONCHANNEL(*it));
				continue;
			}
			channel->removeUser(client);
			channel->sendMessageToAll(client, RPL_PART(channel->getName(), "", client->getNick(), client->getUsername(), "localhost"));
		}
		return true;
	}
}