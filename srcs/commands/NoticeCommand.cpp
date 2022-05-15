/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoticeCommand.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:08:34 by alganoun          #+#    #+#             */
/*   Updated: 2022/05/13 07:38:02 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/NoticeCommand.hpp"
	
namespace ft
{
	NoticeCommand::NoticeCommand() : ClientCommand("NOTICE") {}

	NoticeCommand::~NoticeCommand() {}

	bool NoticeCommand::execute(CommandContext &cmd) const {
		ClientIRC *client = cmd.getClient();
		ServerIRC *server = cmd.getServer();
		std::vector<std::string> args = cmd.getArgs();

		if (args[0][0] == '#')
		{
			std::cout << C_BLUE << "Client " << *client << " want to send the message " 
										<< "'" <<args[1] << "'" << " in the channel " << args[0] <<  C_RESET << std::endl;
			std::vector<ChannelIRC>::iterator channel  = server->getChannels().begin();
			while(channel != server->getChannels().end())
			{
				if (channel->getName() == args[0])
				{	
					channel->sendMessageToAll(client, cmd.getFullCmd());
					return true;
				}
				channel++;
			}
			client->recieveMessage(ERR_NOSUCHCHANNEL(args[0]));
		}
		else
		{
			std::cout << C_BLUE << "Client " << *client << " want to send the message " 
										<< "'" <<args[1] << "'" << " to " << args[0] <<  C_RESET << std::endl;
			std::map<int , ClientIRC *>::iterator user  = server->getClients().begin();
			while(user != server->getClients().end())
			{
				if (user->second->getNick() == args[0])
				{	
					client->sendMessage(user->second, cmd.getFullCmd());
					return true;
				}
				user++;
			}
			client->recieveMessage(ERR_NOSUCHNICK(args[0]));
		}
		return true;
	}
}