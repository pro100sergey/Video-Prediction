#include <userver/server/handlers/http_handler_json_base.hpp>
#include <userver/formats/json.hpp>

#include "current_state.hpp"

namespace api::status::current {
    
class CurrentStatus final : public server::handlers::HttpHandlerJsonBase {
 public:
  static constexpr std::string_view kName = "current-status";

  using HttpHandlerBase::HttpHandlerBase;

  formats::json::Value HandleRequestJsonThrow(
      const server::http::HttpRequest&, const formats::json::Value& json,
      server::request::RequestContext&) const override;
};

} // namespace api::status::current

