//
// Created by Aidan on 2/2/2020.
//

#pragma once

namespace discordpp{
	template<class BASE>
	class PluginOverload: public BASE, virtual BotStruct{
	public:
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
				const std::function<void()> &onWrite
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					nullptr,
					std::make_shared<std::function<void()>>(onWrite),
					nullptr
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const std::function<void(const json)> &onRead
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					nullptr,
					nullptr,
					std::make_shared<std::function<void(const json)>>(onRead)
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body,
				const std::function<void()> &onWrite
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					std::make_shared<std::function<void()>>(onWrite),
					nullptr
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body,
				const std::function<void(const json)> &onRead
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					nullptr,
					std::make_shared<std::function<void(const json)>>(onRead)
			);
		};

		virtual void call(
				const std::string &requestType,
				const std::string &targetURL,
				const json &body,
				const std::function<void()> &onWrite,
				const std::function<void(const json)> &onRead
		){
			BASE::call(
					std::make_shared<std::string>(requestType),
					std::make_shared<std::string>(targetURL),
					std::make_shared<json>(body),
					std::make_shared<std::function<void()>>(onWrite),
					std::make_shared<std::function<void(const json)>>(onRead)
			);
		};

		virtual void send(const int opcode){
			BASE::send(opcode, nullptr, nullptr);
		};

		virtual void send(const int opcode, const json &payload){
			BASE::send(opcode, std::make_shared<json>(payload), nullptr);
		};

		virtual void send(const int opcode, const std::function<void()> &onRead){
			BASE::send(opcode, nullptr, std::make_shared<const std::function<void()>>(onRead));
		};

		virtual void send(const int opcode, const json &payload, const std::function<void()> &onRead){
			BASE::send(opcode, std::make_shared<json>(payload), std::make_shared<const std::function<void()>>(onRead));
		};

		virtual void send(const int opcode, sptr<const json> payload){
			BASE::send(opcode, std::move(payload), nullptr);
		};

		virtual void send(const int opcode, sptr<const std::function<void()>> onRead){
			BASE::send(opcode, nullptr, std::move(onRead));
		};
	};
}