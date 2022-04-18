#include <commands.hpp>

void AboutCommand::on_interaction_create(dpp::cluster* cluster, const dpp::interaction_create_t& event) {

    event.reply(construct_about_message());
}

void AboutCommand::on_button_click(dpp::cluster* cluster, const dpp::button_click_t& event) {
    
    if (event.custom_id == "about_button_1") {

        event.reply(dpp::ir_update_message, construct_latency_message());

    } else if (event.custom_id == "about_button_2") {

        event.reply(dpp::ir_update_message, construct_about_message());
        
    } else if (event.custom_id == "about_button_feedback") {
        
        dpp::interaction_modal_response modal("feedback", "Your Feedback");
        modal.add_component(
            dpp::component().
            set_label("Feedback").
            set_id("feedback_modal").
            set_type(dpp::cot_text).
            set_placeholder("Your feedback here").
            set_min_length(20).
            set_max_length(2000).
            set_text_style(dpp::text_paragraph)
        ).set_custom_id("feedback_modal");

        event.dialog(modal);
        
    }

}

void AboutCommand::on_form_submit(dpp::cluster* cluster, const dpp::form_submit_t& event) {

    std::string v = std::get<std::string>(event.components[0].components[0].value);
        
    dpp::message m;
    dpp::embed e;

    e.set_title("Thank you for your feedback!");
    e.set_color(EMBED_COLOR);
    e.set_description(v);

    m.add_embed(e);
    m.set_flags(dpp::m_ephemeral);
    event.reply(m);

    dpp::message dm;
    dpp::embed de;

    de.set_title(fmt::format("Feedback from {}#{} ({})", event.command.usr.username, event.command.usr.discriminator, event.command.usr.id));
    de.set_color(EMBED_COLOR_DEV);
    de.set_description(v);

    dm.add_embed(de);
    cluster->direct_message_create(456858239037079572, dm);
}

dpp::message AboutCommand::construct_about_message() {

    dpp::message m;
    dpp::embed e;
    
    e.set_title("Bot Information");
    e.set_color(EMBED_COLOR);
    e.add_field("Version", BOT_VERSION_TEXT, true);
    e.add_field("Library", LIBRARY_VERSION_TEXT, true);
    m.add_embed(e);
    add_components(m, false);

    return m;
}

dpp::message AboutCommand::construct_latency_message() {

    dpp::message m;
    dpp::embed e;

    
    e.set_title("Bot latency");
    e.set_description("Still in development");

    e.set_color(EMBED_COLOR);
    m.add_embed(e);
    add_components(m, true);

    return m;
}

void AboutCommand::add_components(dpp::message& m, bool sw) {
    m.add_component(
        dpp::component().
            add_component(
                dpp::component().set_type(dpp::cot_button).
                set_label("View latency").
                set_style(dpp::cos_primary).
                set_disabled(sw).
                set_id("about_button_1")
            ).
            add_component(
                dpp::component().set_type(dpp::cot_button).
                set_label("Bot information").
                set_style(dpp::cos_primary).
                set_disabled(!sw).
                set_id("about_button_2")
            )
    ).add_component(
        dpp::component().
            add_component(
                dpp::component().set_type(dpp::cot_button).
                set_label("Github Bot").
                set_style(dpp::cos_link).
                set_url("https://github.com/Fubuki-gh/WaifuBot").
                set_id("about_button_3")
                ).
            add_component(
                dpp::component().set_type(dpp::cot_button).
                set_label("Github library").
                set_style(dpp::cos_link).
                set_url("https://github.com/brainboxdotcc/DPP").
                set_id("about_button_4")
            )
    ).add_component(
        dpp::component().
            add_component(
                dpp::component().set_type(dpp::cot_button).
                set_label("Feedback").
                set_style(dpp::cos_success).
                set_id("about_button_feedback")
            )
    );
}
