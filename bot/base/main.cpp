#include <iostream>
#include "Server.hpp"
#include "Client.hpp"
#include "BotState.hpp"

using namespace std;

int main()
{
    Message m1("test", {{"test2", "test3"}});
    Message m3("test1234", {{"test2", "test3"}});
    Server s(8080);
    Client c("127.0.0.1", 8080);
    s.init();
    c.start();
    s.handleNewConnection();
    s.deliver(m1);
    Message m2 = c.recieve();
    cout << m2.flatten() << endl;
    c.deliver(m3);
    m2 = s.recieve();
    cout << m2.flatten() << endl;
    c.stop();
    s.shutdown();
    return 0;
}