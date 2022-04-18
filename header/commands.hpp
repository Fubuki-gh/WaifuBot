#pragma once
#include <waifubot.hpp>


class Command {
public:
    virtual void on_interaction_create(dpp::cluster* cluster, const dpp::interaction_create_t& event);
    virtual void on_button_click(dpp::cluster* cluster, const dpp::button_click_t& event);
    virtual void on_form_submit(dpp::cluster* cluster, const dpp::form_submit_t& event);
    virtual void on_select_click(dpp::cluster* cluster, const dpp::select_click_t& event);
};

class AboutCommand : public Command {
public:
    void on_interaction_create(dpp::cluster* cluster, const dpp::interaction_create_t& event) override;
    void on_button_click(dpp::cluster* cluster, const dpp::button_click_t& event) override;
    void on_form_submit(dpp::cluster* cluster, const dpp::form_submit_t& event) override;
private:
    dpp::message construct_about_message();
    dpp::message construct_latency_message();
    void add_components(dpp::message& m, bool sw);
};
