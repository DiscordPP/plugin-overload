//
// Created by Aidan on 2/2/2020.
//

#pragma once

#include <discordpp/botStruct.hh>

namespace discordpp {
template <class BASE> class PluginOverload : public BASE, virtual BotStruct {
  public:
    using BASE::send;

    virtual void send(const int opcode) {
        BASE::send(opcode, nullptr, nullptr);
    };

    virtual void send(const int opcode, const json &payload) {
        BASE::send(opcode, std::make_shared<json>(payload), nullptr);
    };

    virtual void send(const int opcode, const handleSent &onRead) {
        BASE::send(opcode, nullptr, std::make_shared<const handleSent>(onRead));
    };

    virtual void send(const int opcode, const json &payload,
                      const handleSent &onRead) {
        BASE::send(opcode, std::make_shared<json>(payload),
                   std::make_shared<const handleSent>(onRead));
    };

    virtual void send(const int opcode, sptr<const json> payload) {
        BASE::send(opcode, std::move(payload), nullptr);
    };

    virtual void send(const int opcode, sptr<const handleSent> onRead) {
        BASE::send(opcode, nullptr, std::move(onRead));
    };
};
} // namespace discordpp