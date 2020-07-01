//
// Created by Aidan on 2/2/2020.
//

#pragma once

#include <discordpp/botStruct.hh>

namespace discordpp{
	template<class BASE>
	class PluginOverload: public BASE, virtual BotStruct{
	public:
		using BASE::call;
		using BASE::send;
		
		virtual void call(
				const std::string &requestType,
				const std::string &targetURL
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					nullptr,
					nullptr,
					nullptr
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					nullptr,
					nullptr
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const handleWrite &onWrite
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					nullptr,
					std::make_shared<handleWrite>(onWrite),
					nullptr
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const handleRead &onRead
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					nullptr,
					nullptr,
					std::make_shared<handleRead>(onRead)
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body,
				const handleWrite &onWrite
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					std::make_shared<handleWrite>(onWrite),
					nullptr
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body,
				const handleRead &onRead
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					nullptr,
					std::make_shared<handleRead>(onRead)
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body,
				const handleWrite &onWrite,
				const handleRead &onRead
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					std::make_shared<handleWrite>(onWrite),
					std::make_shared<handleRead>(onRead)
			);
		};

		virtual void send(const int opcode){
			BASE::send(opcode, nullptr, nullptr);
		};

		virtual void send(const int opcode, const json &payload){
			BASE::send(opcode, std::make_shared<json>(payload), nullptr);
		};

		virtual void send(const int opcode, const handleSent &onRead){
			BASE::send(opcode, nullptr, std::make_shared<const handleSent>(onRead));
		};

		virtual void send(const int opcode, const json &payload, const handleSent &onRead){
			BASE::send(opcode, std::make_shared<json>(payload), std::make_shared<const handleSent>(onRead));
		};

		virtual void send(const int opcode, sptr<const json> payload){
			BASE::send(opcode, std::move(payload), nullptr);
		};

		virtual void send(const int opcode, sptr<const handleSent> onRead){
			BASE::send(opcode, nullptr, std::move(onRead));
		};
	};
}