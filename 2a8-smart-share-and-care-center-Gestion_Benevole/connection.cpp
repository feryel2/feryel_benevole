#include "connection.h"
//tester Git

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
/*db.setDatabaseName("projet_2A");
db.setUserName("feryel");//inserer nom de l'utilisateur
db.setPassword("feryel");//inserer mot de passe de cet utilisateur
*/
db.setDatabaseName("projet_2A");
db.setUserName("feryel");//inserer nom de l'utilisateur
db.setPassword("feryel");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection:: closeconnection()
{
    db.close();
}

