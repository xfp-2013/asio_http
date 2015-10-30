#include <iostream>
#include <http/server.hpp>
#include <http/request.hpp>
#include <http/reply.hpp>

int main(int argc, char *argv[]) {
  // Initialise the server.
  using namespace http::server;
  server s("127.0.0.1", "8080", 1);

  s.add_handler("/hello", [](const request &req, reply &rep) {
    rep.content = "hello world!";
    rep.status = reply::ok;
    rep.headers.emplace_back("Content-Length", std::to_string(rep.content.size()));
    rep.headers.emplace_back("Content-Type", "text/plain");
  });

  // Run the server until stopped.
  s.run();
  return 0;
}