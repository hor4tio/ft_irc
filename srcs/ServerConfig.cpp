/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:10:32 by tglory            #+#    #+#             */
/*   Updated: 2022/05/08 18:33:42 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ServerConfig.hpp"

namespace ft {

	ServerConfig::ServerConfig() : port(-1), password(""), ip("0.0.0.0") {}

	ServerConfig::ServerConfig(int& port, std::string& password) : port(port), password(password), ip("0.0.0.0") {}

	ServerConfig& ServerConfig::operator=(const ServerConfig& x) {
		this->setPassword(x.getPassword());
		this->setPort(x.getPort());
		return *this;
	}

	bool ServerConfig::set(const int ac, const char *av[]) {
		if (ac < 3) {
			std::cerr << C_RED << "Usage > " << av[0] << " <port> <password>" << C_RESET << std::endl;
			return false;
		} else if (!this->setPort(av[1])) {
			std::cerr << ERROR << "Port should be between 0-65535" << C_RESET << std::endl;
			return false;
		} else if (!this->setPassword(av[2])) {
			std::cerr << ERROR << "Password not valid" << C_RESET << std::endl;
			return false;
		}
		return true;
	}

	bool ServerConfig::setPort(const char* port) {
		int intPort = std::atoi(port);
		if (std::strspn(port, "0123456789") != std::strlen(port))
			return false;
		return setPort(intPort);
	}

	bool ServerConfig::setPort(const int& port) {
		if (port < 0 || port > 65535)
			return false;
		this->port = port;
		return true;
	}

	bool ServerConfig::setPassword(const std::string& password) {
		this->password = password;
		return true;
	}

	const std::string& ServerConfig::getPassword() const {
		return this->password;
	}

	const int& ServerConfig::getPort() const {
		return this->port;
	}

	bool ServerConfig::setIP(const std::string& ip) {
		this->ip = ip;
		return true;
	}

	const std::string& ServerConfig::getIP() const {
		return this->ip;
	}
}
