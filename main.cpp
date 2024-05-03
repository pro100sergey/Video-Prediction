#include <userver/utest/using_namespace_userver.hpp>

/// [Hello service sample - component]
#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/http_handler_base.hpp>
#include <userver/utils/daemon_run.hpp>
#include <userver/logging/log.hpp>

#include <userver/server/handlers/http_handler_json_base.hpp>

// #include <api/get/current_status.hpp>
// #include <api/get/settings.hpp>
// #include <api/post/change_status.hpp>
// #include <api/post/stop.hpp>

namespace samples::hello {

class Hello final : public server::handlers::HttpHandlerJsonBase {
 public:
  // `kName` is used as the component name in static config
  static constexpr std::string_view kName = "handler-hello-sample";

  // Component is valid after construction and is able to accept requests
  using HttpHandlerJsonBase::HttpHandlerJsonBase;

  // std::string HandleRequestThrow(
  //     const server::http::HttpRequest& r,
  //     server::request::RequestContext&) const override {
  //   std::string temp = r.GetPathArg("name");
  //   return temp;
  // }


 
  formats::json::Value HandleRequestJsonThrow(
    const server::http::HttpRequest&,
    const formats::json::Value&,
    server::request::RequestContext&
  ) const {
    formats::json::ValueBuilder result;
  
    result["configs"] = "BASE";
  
    result["updated_at"] = utils::datetime::Now();
  
    return result.ExtractValue();
  }

};

}  // namespace samples::hello
/// [Hello service sample - component]

/// [Hello service sample - main]
int main(int argc, char* argv[]) {
  const auto component_list =
      components::MinimalServerComponentList().Append<samples::hello::Hello>();
  return utils::DaemonMain(argc, argv, component_list);
}
/// [Hello service sample - main]
