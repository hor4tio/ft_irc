/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:05:54 by tglory            #+#    #+#             */
/*   Updated: 2022/05/23 17:17:38 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commands/ExitCommand.hpp"

namespace ft {

	ExitCommand::ExitCommand() : ClientCommand("EXIT", true, true) {}

	ExitCommand::~ExitCommand() {}

	bool ExitCommand::execute(CommandContext &cmd) const {
		ServerIRC *server = cmd.getServer();
		
		server->stop();
		return true;
	}
}
