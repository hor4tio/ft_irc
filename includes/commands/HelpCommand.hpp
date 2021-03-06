/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:53:37 by tglory            #+#    #+#             */
/*   Updated: 2022/05/25 18:46:14 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClientCommand.hpp"
#include "CommandManager.hpp"

namespace ft {
	class HelpCommand : public ClientCommand {

		public :
			HelpCommand();

			~HelpCommand();

			bool execute(CommandContext &cmd) const;
	};
}
