#include <iostream>///cout,cin, and a lot other
#include <cstdio>///As following
#include <cstdlib>///New compiler don't need this
#include <vector>///For future
#include <random>///Random Device
#include <cstring>///stoi, atoi
#include <cmath>///abs
#include <memory>///shared_ptr
#include <limits>///using Limits
#include <fstream>///file


///MACRO

#define ADMIN_PATH_LOGIN "a_BIN_LOG.bin"
#define ADMIN_PATH_PASS "a_BIN_HASH_PASS.bin"
#define DEFAULT_DATE "admin"
#define NAME_OF_AUTHOR "Szymon Ryl"
#define BASE_NAME "serial_Base.txt"
#define BASE_OF_PRODUCT "base_of_Product.txt"
#define SERIAL_BASE "list_Of_Product.txt"

///Default login & pass for admin is : "admin" "admin" without quotes




class Class_For_Static
{
public:

    unsigned static int used
    ,num_Of_Product
    ,el_Used;
    static std::string list_Prod;
    static bool isset;
    static std::string actual_User;
private:

    Class_For_Static() {}
    Class_For_Static & operator =(const Class_For_Static &Obj)
    {
        return *this;
    }
    Class_For_Static(const Class_For_Static &obj)
    {
        std::cerr<<"Cannot create object"<<'\n';
        exit(-1);
    }
};
std::string Class_For_Static::list_Prod="";
std::string Class_For_Static::actual_User="";
unsigned int Class_For_Static::el_Used=0;
unsigned int Class_For_Static::num_Of_Product=0;
unsigned int Class_For_Static::used=0;
bool Class_For_Static::isset=false;
class list_Of_Ours_Product;
class User;
class list_Of_Ours_Product
{
private:
    std::string name;
    std::string info;
    unsigned int price
    , how_Much;

public:

    friend class Observer;

    list_Of_Ours_Product();
    list_Of_Ours_Product(const list_Of_Ours_Product &);
    ~list_Of_Ours_Product() {}
    void add_Item(list_Of_Ours_Product *&o);
    void show_Info(const list_Of_Ours_Product o[]);
    void deleting_Item()
    {
    ///    std::shared_ptr<list_Of_Ours_Product> obj1(new list_Of_Ours_Product);   ///I know that is wrong way, but i like this
    }
    void buying_Item(list_Of_Ours_Product *&o);
    void remove_Item(list_Of_Ours_Product *&o);
    bool test(unsigned int decision);
    void loading(std::string,list_Of_Ours_Product *&o,const bool);
};
void mem_Allocation(list_Of_Ours_Product *&o);
void list_Of_Ours_Product::loading(std::string file_Name,list_Of_Ours_Product *&o,const bool wheter_Save)
{

    std::ifstream ff(file_Name,std::ifstream::in);
    if(ff.good())
    {


        std::string where_Do_You_Go="";
        unsigned int number_Of_Repetitions=1;


        while(std::getline(ff,where_Do_You_Go))
        {
            switch(number_Of_Repetitions)
            {
            default:
                {
                    std::cout<<"Loading... "<<'\n';

                    std::ifstream ff(where_Do_You_Go+".bin",std::ifstream::binary);

                    if(ff)
                    {
                        ff.seekg(0,ff.end);
                        int length=ff.tellg();
                        ff.seekg(0);
                        char * here_Will_Text;
                        here_Will_Text=new char [length];
                        ff.read(here_Will_Text,length);

                        std::string temporarity_For_Save_Of_Object="";


                        if(ff)
                        {
                        int stop=0;

                            for(int i=0;i<length;i++)
                            {

                                if(here_Will_Text[i]=='\n')
                                {
                                    stop=i;

                                    break;
                                }
                                else temporarity_For_Save_Of_Object+=here_Will_Text[i];

                            }

                   // std::cout<<"Static: "<<Class_For_Static::num_Of_Product<<" number: "<<number_Of_Repetitions<<'\n';


                            if(wheter_Save)o[number_Of_Repetitions-1].price=std::stoi(temporarity_For_Save_Of_Object);


                            if(wheter_Save)o[number_Of_Repetitions-1].name=where_Do_You_Go;
                             //std::cout<<"Static: "<<Class_For_Static::num_Of_Product<<" number: "<<number_Of_Repetitions<<'\n';
                            temporarity_For_Save_Of_Object="";

                            for(int i=stop+2;i<length;i++)
                            {

                                if(here_Will_Text[i]=='\n')
                                {

                                    stop=i;

                                    break;
                                }
                                else temporarity_For_Save_Of_Object+=here_Will_Text[i];

                            }











                            if(wheter_Save)o[number_Of_Repetitions-1].how_Much=std::stoi(temporarity_For_Save_Of_Object.c_str());
                            temporarity_For_Save_Of_Object="";
                            //std::cout<<"\nAdditional information: \n";
                            for(int i=stop+1;i<length;i++)
                            {
                                temporarity_For_Save_Of_Object+=here_Will_Text[i];
                            }

                            if(wheter_Save)o[number_Of_Repetitions-1].info=temporarity_For_Save_Of_Object;

                        }
                        else std::cout<<"I can only read: "<<ff.gcount()<<'\n';

                        delete [] here_Will_Text;
                        ff.close();
                    }
                    else std::cout<<"Binary file can't open..."<<'\n';


                }
            }
            number_Of_Repetitions++;
            Class_For_Static::num_Of_Product=number_Of_Repetitions;

        }


        ff.close();




    }



}
namespace save
{
void saving(std::string file_Name,std::string what_Save)
{

    std::fstream ff(file_Name+".bin",std::ofstream::binary | std::ofstream::app);
    what_Save+='\n';




    ff.write(what_Save.data(),what_Save.length()+1);



    ff.close();
}

void saving(std::string file_Name,std::string what_Save,const bool special_For_Macro)
{


    std::ofstream ff;
    ff.open(file_Name,std::ofstream::out | std::ofstream::app);


    ff<<what_Save<<'\n';///This should be a control version

    ff.close();
}
}

class Virtual_For_User
{
public:
    virtual void registration(list_Of_Ours_Product *&o)=0;
    virtual void sign_In(const User *& us_Obj)=0;
    virtual void log_Out()=0;
    virtual void login_For_User(list_Of_Ours_Product*&o)=0;
    virtual void base_Of_User(const bool searching_User,const std::string login_Fname,const std::string pass_Fname,list_Of_Ours_Product *&o)=0;
   // virtual void save_Buying_Item(std::string user_Id,std::string name_Buying_Product,int how_Many_Buying)=0;
   // virtual void save_From_Buying_Item()=0;
   // virtual void open_From_Buying_Item()=0;
    //virtual void registration_File(list_Of_Ours_Product *&o,std::string fname,std::string pass_User)=0;

};
class User:public Virtual_For_User
{
    std::string name
    ,pass
    ,login
    ,temp_Pass
    ,temp_Login;
    int id;


public:
    static unsigned int h_Much;
    User():name("ERROR"),pass("ERROR_PASS"),login(""),id(0)
    {
        //User::h_Much++;
    }
    void registration(list_Of_Ours_Product *&o);
    void sign_In(const User *& us_Obj);///Logowanie
    void log_Out();
    void base_Of_User(const bool searching_User,const std::string login_Fname,const std::string pass_Fname,list_Of_Ours_Product *&o);
    void base_Of_User(std::string fname);
    void login_For_User(list_Of_Ours_Product*&o);
    void base_Of_Item(std::string fname,std::string where_is_Path);
    void save_Buying_Item(std::string user_Id,std::string name_Buying_Product,int how_Many_Buying);
    void load_User_Shopping();
};
class Special_For_User
{
public:
    void save_From_Buying_Item(std::string fname);
    void open_From_Buying_Item(list_Of_Ours_Product *&o,const bool);
};
void Special_For_User::save_From_Buying_Item(std::string fname)
{
    std::ofstream ff;
    ff.open(SERIAL_BASE,std::ofstream::out | std::ofstream::app);

    fname+='\n';
    ff.write(fname.data(),fname.length()+1);

    ff.close();
}
void Special_For_User::open_From_Buying_Item(list_Of_Ours_Product *&o,const bool wheter_Save)
{

    o->loading(SERIAL_BASE,o,wheter_Save);


}
unsigned int User::h_Much=0;
int main();
void User::save_Buying_Item(std::string id,std::string name_Buying_Product,int how_Many_Buying)
{
    std::string concatenation_Of_String_And_Int;
    concatenation_Of_String_And_Int=name_Buying_Product;
    concatenation_Of_String_And_Int+='\n';

    concatenation_Of_String_And_Int+=std::to_string(how_Many_Buying);


    save::saving(id+"_buying",concatenation_Of_String_And_Int);

}
void User::load_User_Shopping()
{
    std::ifstream load(Class_For_Static::actual_User+"_buying.bin",std::ifstream::binary);
    if(load)
    {

        load.seekg(0,load.end);
        int length=load.tellg();
        load.seekg(0);

        char *where_Will_Go=new char [length];

        load.read(where_Will_Go,length);

        if(load)
        {
            printf("%s","Everything is good...\n");
            int stop=0;
            std::cout.width(30);
            std::cout<<"Name of item: "<<" ";
            for(int i=0; i<length; i++){
                    if(where_Will_Go[i]=='\n')
                    {
                        stop=i;
                        break;
                    }
                else std::cout<<where_Will_Go[i];
                }
                std::cout<<'\n';
                std::cout.width(30);
                std::cout<<"You buying: "<<" ";

                for(int i=stop+1;i<length;i++)
                {
                    if(where_Will_Go[i]=='\n')break;
                    else std::cout<<where_Will_Go[i];
                }

                std::cout<<" item/s "<<'\n';
        }


        else printf("%s,%i,%s","ERROR! I ONLY COULD READ: ",load.gcount(),"CHARSET");
         delete [] where_Will_Go;
    load.close();
    }
}
class Administration_Class
{
public:
    virtual void change_Password(list_Of_Ours_Product *&o)=0;
};
class Admin;
class Files : public Administration_Class
{

    std::string pass
    ,login;
    int length;
    char * where_Will_Go;
public:

    ~Files();
    Files();
    Files(const Files& F);
    /*Files & operator =(const Files &obj)
    {
        pass=obj.pass;
        login=obj.login;
        where_Will_Go=obj.where_Will_Go;
        return *this;
    }*/
    friend class Admin;
    void change_Password(list_Of_Ours_Product *&o);
    void change_Login(list_Of_Ours_Product *&o);
    void load_Pass_Login(const std::string,const bool);
    void opening_Sesame(list_Of_Ours_Product *&o,const bool);///login is zero, pass is one
    void opening_Sesame(list_Of_Ours_Product *&o,const bool, Files &f1);
    void reset_To_Default(list_Of_Ours_Product *&o);
    void registration_File(list_Of_Ours_Product *&o,std::string fname,std::string pass_User);

    void load_All_User();

};
class Admin
{
public:
    void login_Of_Administator(list_Of_Ours_Product *&);




};
class Rediction_From_User
{

public:
    static void rediction_To_Location(Virtual_For_User *where_Redict,list_Of_Ours_Product*&o)
    {
        where_Redict->login_For_User(o);
    }
};
void control_Panel(bool,list_Of_Ours_Product *&);
void Admin::login_Of_Administator(list_Of_Ours_Product *&o)
{
    Files f1;
    f1.opening_Sesame(o,0,f1);
    std::string log_Admin
    ,pass_Admin;




    std::cout<<"Enter your login: "<<'\n';
    std::cin>>log_Admin;
    std::cout<<"Enter your pass: "<<'\n';
    std::cin>>pass_Admin;
    if(log_Admin==f1.login&&pass_Admin==f1.pass)
    {
        control_Panel(1,o);
    }
    // std::cout<<f1.login<<'\n';
}
Files::Files(const Files &F):pass(F.pass),login(F.login),length(1),where_Will_Go(F.where_Will_Go)
{

}

Files::Files():pass(DEFAULT_DATE),login(DEFAULT_DATE),length(1),where_Will_Go(new char [length])
{
    for(int i=0; i<length; i++)
        where_Will_Go[i]='!';
}

Files::~Files()
{
    delete [] where_Will_Go;

}
void Files::load_All_User()
{

}
void User::base_Of_User(const bool searching_User,const std::string login_Fname,const std::string pass_Fname,list_Of_Ours_Product *&o)
{

    std::ifstream ff;
    ff.open(BASE_NAME,std::ifstream::in);
    if(ff)
    {


        //User h_Many_User[User::h_Much];///Should be a virtual destructor

        std::string where_Do_You_Go="";
        int number_Of_Repetitions=1;///Powtorzenia
        Virtual_For_User *V_U=nullptr;
        bool find_User=false;
        while(std::getline(ff,where_Do_You_Go))
        {

            switch(number_Of_Repetitions)
            {
            default:
            {
                std::cout<<"I loaded users..."<<'\n';

                if(searching_User==true && where_Do_You_Go==login_Fname)
                {
                    find_User=true;

                    std::cout<<"I found user with this login. Searching pass..."<<'\n';
                    std::ifstream f_User(login_Fname+".bin",std::ifstream::binary);
                    f_User.seekg(0,f_User.end);
                    int length=f_User.tellg();
                    f_User.seekg(f_User.beg);


                    if(f_User)
                    {


                        char * check_Pass_User=new char [length];
                        f_User.read(check_Pass_User,length);
                        if(f_User)
                        {
                            unsigned int stop_For=0;
                            for( int i=0; i<length; i++)
                            {
                                if(check_Pass_User[i]==' ')
                                {
                                    stop_For=i;
                                    break;
                                }
                            }
                            if(stop_For!=0)
                            {


                                bool really_Pass=0;
                                int counter_For_Pass=0;///Licznik dla hasla
                                for( int i=stop_For+1; i<length; i++)
                                {


                                    if(check_Pass_User[i]==' ')break;
                                    else
                                    {

                                        if(pass_Fname[counter_For_Pass]!=check_Pass_User[i])
                                        {
                                            //std::cout<<pass_Fname[i]<<" "<<check_Pass_User[i]<<'\n';
                                            really_Pass=0;
                                            break;
                                        }
                                        else
                                        {


                                            really_Pass=1;
                                        }
                                    }
                                    counter_For_Pass++;
                                }
                                if(really_Pass)
                                {
                                    std::cout<<"Okay,wait for sing in !"<<'\n';
                                    control_Panel(0,o);
                                }
                                else
                                {
                                    std::cout<<"Try again..."<<'\n';
                                    User uObject;
                                    V_U=&uObject;
                                    Rediction_From_User::rediction_To_Location(V_U,o);
                                }

                            }
                            else std::cout<<"ERROR! "<<'\n';

                        }
                        else std::cout<<"I can read: "<<f_User.gcount()<<'\n';

                        delete [] check_Pass_User;

                        f_User.close();
                    }
                    else std::cout<<"Something error..."<<'\n';


                    ff.close();
                }


            }

            number_Of_Repetitions++;
            User::h_Much=number_Of_Repetitions;

                /*
                for(unsigned int i=0;i<where_Do_You_Go.length();i++){
                     if(where_Do_You_Go[i]==' ')
                     pass[i]=where_Do_You_Go[i];
                 else login[i]=where_Do_You_Go[i];
                }

                h_Many_User[number_Of_Repetitions-1].login=login;
                h_Many_User[number_Of_Repetitions-1].pass=pass;
                number_Of_Repetitions++;
                */
            }
        }
        if(searching_User==true && find_User==false)
        {
            std::cout<<"I can't find user! login equal: "<<login_Fname<<" Where_Do_You_Go: "<<where_Do_You_Go<<'\n';

            User uObject;
            V_U=&uObject;
            Rediction_From_User::rediction_To_Location(V_U,o);
        }
        //std::cout<<"Po calej iteracji login: "<<h_Many_User[0].login<<" password: "<<h_Many_User[0].pass<<'\n';
    }
    else std::cout<<"I can't open!"<<'\n';


    ff.close();
   // std::cout<<"TUTAJ JEST WSZYSTKO DOBRZE"<<'\n';
}
void User::base_Of_User(std::string fname)
{
    std::ofstream ff;
    ff.open(BASE_NAME,std::ofstream::out | std::ofstream::app);


    ff<<fname<<'\n';

    ff.close();
}
void User::base_Of_Item(std::string fname,std::string where_is_Path)
{
    std::ofstream ff;
    ff.open(where_is_Path+".txt",std::ofstream::out | std::ofstream::app);


    ff<<fname<<'\n';

    ff.close();
}
void Files::registration_File(list_Of_Ours_Product *&o,const std::string fname,const std::string pass_User)
{
    std::ofstream ff;
    ff.open(fname+".bin",std::ios::binary);
    std::string connection_Login_Pass=fname;
    connection_Login_Pass+=" ";
    connection_Login_Pass+=pass_User;

    ff.write(connection_Login_Pass.data(),connection_Login_Pass.size()+1);
    User u1;
    u1.base_Of_User(fname);

    ff.close();
}

void Files::opening_Sesame(list_Of_Ours_Product *&o,const bool decision, Files &f1)
{



    f1.load_Pass_Login(ADMIN_PATH_LOGIN,0);
    f1.load_Pass_Login(ADMIN_PATH_PASS,1);

    if(decision)std::cout<<"Login: "<<f1.login<<'\n'
                             <<"Pass: "<<f1.pass<<'\n';
    //control_Panel(1,o);

}
void Files::opening_Sesame(list_Of_Ours_Product *&o,const bool decision)
{
    Files f1;


    f1.load_Pass_Login(ADMIN_PATH_LOGIN,0);
    f1.load_Pass_Login(ADMIN_PATH_PASS,1);

    if(decision)std::cout<<"Login: "<<f1.login<<'\n'
                             <<"Pass: "<<f1.pass<<'\n';
    //control_Panel(1,o);

}
void Files::change_Login(list_Of_Ours_Product *&o)
{

    std::cout<<"Insert login: "<<'\n';
    std::ofstream save(ADMIN_PATH_LOGIN,std::ofstream::binary);

    std::cin>>login;

    save.write(login.data(),login.length()+1);///add zero. Says, when string variables length is ending


    save.close();
    control_Panel(1,o);
}
void Files::reset_To_Default(list_Of_Ours_Product *&o)
{
    std::cout<<"Insert login: "<<'\n';
    std::ofstream save_Log(ADMIN_PATH_LOGIN,std::ofstream::binary);
#undef ADMIN_PATH_LOGIN
    login="admin";///I know, that constructor have a "admin"

    save_Log.write(login.data(),login.length()+1);///add zero. Says, when string variables length is ending


    save_Log.close();

    std::cout<<"Insert password: "<<'\n';
    std::ofstream save_Pass(ADMIN_PATH_PASS,std::ofstream::binary);

    pass=login;


    save_Pass.write(pass.data(),pass.length()+1);///add zero


    save_Pass.close();


    control_Panel(1,o);

}
void Files::change_Password(list_Of_Ours_Product *&o)
{
    std::cout<<"Insert password: "<<'\n';
    std::ofstream save(ADMIN_PATH_PASS,std::ofstream::binary);
#undef ADMIN_PATH_PASS
    std::cin>>pass;

    save.write(pass.data(),pass.length()+1);///add zero


    save.close();


    control_Panel(1,o);

}
void Files::load_Pass_Login(const std::string fname,const bool log_Or_Pass)
{
    std::ifstream load(fname,std::ifstream::binary);


    if(load)
    {

        load.seekg(0,load.end);
        int length=load.tellg();
        load.seekg(0);

        where_Will_Go=new char [length];

        load.read(where_Will_Go,length);

        if(load)
        {
            printf("%s","Everything is good...\n");

            if(!log_Or_Pass)login=(std::string)where_Will_Go;
            else pass=(std::string)where_Will_Go;

        }

        else printf("%s,%i,%s","ERROR! I ONLY COULD READ: ",load.gcount(),"CHARSET");




        ///Maybe better calls destructor ?
        delete [] where_Will_Go;

        load.close();

    }

    else std::cout<<"Can't load...";


}
void User::log_Out()
{
    std::cout<<"Forwarding to login..."<<'\n';
    //User();
    exit(0);

}
void User::registration(list_Of_Ours_Product *&o)
{

    std::cout<<"Insert your name: "<<'\n';
    std::cin>>name;
    std::cout<<"Okay, now insert your pass: "<<'\n';
    std::cin>>pass;
    std::random_device rd;///I know, that mingw and Windows don't support rd
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> dist(0,100+User::h_Much);
    int value=dist(gen);
    login=name+std::to_string(User::h_Much+value);

    std::cout<<"REMEMBER: "<<'\n';
    std::cout<<"Your login: "<<login<<'\n';
    std::cout<<"Your pass: "<<pass<<'\n';
    Files f1;
    f1.registration_File(o,login,pass);
}

void User::sign_In(const User *& us_Obj)
{
    std::cout<<"Insert your name: "<<'\n';
    std::cin>>temp_Login;
    std::cout<<"Okay, now insert your pass: "<<'\n';
    std::cin>>temp_Pass;
    Class_For_Static::actual_User=temp_Login;

    bool finding=false;

    for(unsigned int i=0; i<Class_For_Static::num_Of_Product; i++)
    {
        if(us_Obj[i].login==temp_Login)
        {
            finding=true;

            break;
        }
        if(unsigned (i-1)==Class_For_Static::num_Of_Product && finding ==false)
        {
            std::cout<<"Can't find item.."<<'\n';
            main();
        }
    }
    if(finding==1)
    {
        std::cout<<"Everything is good. Please wait for ending..."<<'\n';
        //std::cout<<"End for: "<<stop<<'\n';
    }
    else
    {
        std::cout<<"Don't find anything..."<<'\n';
        main();
    }
}

class Observer
{

public:

    void obs_Obj(const list_Of_Ours_Product *& o);


};
void Observer::obs_Obj(const list_Of_Ours_Product*&o)
{
    if(o)std::cout<<"how_Much"<<Class_For_Static::num_Of_Product<<" was be initiated"<<o[Class_For_Static::num_Of_Product].how_Much<<'\n'
                      <<"Name object: "<<Class_For_Static::num_Of_Product<<"was be initiated VALUE: "<<o[Class_For_Static::num_Of_Product].name<<'\n'
                      <<"Info object: "<<Class_For_Static::num_Of_Product<<"was be initiated VALUE: "<<o[Class_For_Static::num_Of_Product].info<<'\n'
                      <<"Price object: "<<Class_For_Static::num_Of_Product<<"was be initiated VALUE: "<<o[Class_For_Static::num_Of_Product].price<<'\n';
}
void User::login_For_User(list_Of_Ours_Product*&o)
{

    std::cout<<"Get your login: "<<'\n';
    std::cin>>login;
    std::cout<<"Okay... Now, get your pass: "<<'\n';
    std::cin>>pass;
    Class_For_Static::actual_User=login;
    User u1;

    u1.base_Of_User(1,login,pass,o);


}
bool list_Of_Ours_Product::test(const unsigned int decision)
{
    if(decision>= Class_For_Static::num_Of_Product|| decision<0)return false;
    else return true;
}



list_Of_Ours_Product::list_Of_Ours_Product():name("ERROR"),info(""),price(1),how_Much(1)
{
    Class_For_Static::used++;
}

list_Of_Ours_Product::list_Of_Ours_Product(const list_Of_Ours_Product & l):name(l.name),info(l.info),price(l.price),how_Much(l.how_Much)
{


}


void everything_Is_Good(unsigned short y_D,list_Of_Ours_Product *&o);


void list_Of_Product(list_Of_Ours_Product *&o);
void controler_Panel(int (defin));
void error_Mem_Alloc()
{
    printf("%s","ERROR! BAD MEMORY ALLOC");
    exit(-1);
}


void mem_Allocation(list_Of_Ours_Product *&o)
{
    /*
    list_Of_Ours_Product *b;
        b=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];
        *b=*o;
        ///memmove(b,o,sizeof(*o)*(Class_For_Static::num_Of_Product));
        delete [] o;
        ///o=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];
        o=b;
        */
    std::set_new_handler(error_Mem_Alloc);
    if(Class_For_Static::num_Of_Product==0)
    {

        list_Of_Ours_Product* c=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];
        *c=*o;
        delete [] o;

        o=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];



        *o=*c;
        delete [] c;
    }

    else
    {
        list_Of_Ours_Product* c=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];

        std::cout<<sizeof(o)<<'\n';

        for(unsigned int i=0; i<Class_For_Static::num_Of_Product; i++) ///sizeof(o)/4 is stupid idea :P
        {

            c[i]=o[i];

        }



        delete [] o;
        //o=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];
        o=c;
        //delete []c;
    }
    ///delete [] b;
}
void thanks_For_Use()
{
    std::cout<<"Thanks, for using my program.It was be create a "<<NAME_OF_AUTHOR<<'\n';
#undef NAME_OF_AUTHOR
    exit(0);
}
void control_Panel(bool decision_Admin,list_Of_Ours_Product *&o)
///void control_Panel(bool decision_Admin)
{


    //mem_Allocation(o);

    /*
    if(Class_For_Static::num_Of_Product>90){
    printf("%s","WARRING!\n remained:");///delete *this dla obiektu ktory mozna usunac
    printf("%i",(100-Class_For_Static::num_Of_Product));
    printf("%s","empty place...");
    }
    if(Class_For_Static::num_Of_Product>98)
    {
        std::cout<<"Can't create a new object..."<<'\n';

        return;
    }
    */


    //Class_For_Static::el_Used>0?ile=Class_For_Static::el_Used-1:Class_For_Static::el_Used;
    std::cout<<"Hello in you panel, ";
    decision_Admin==1?std::cout<<"Admin"<<'\n':std::cout<<"Your login: "<<Class_For_Static::actual_User<<'\n';


    std::cout<<"Press: "<<'\n';

    decision_Admin?std::cout
                            <<"0.Show details information about items..."<<'\n'
                            <<"1.Add item to database..."<<'\n'
                            <<"2.Remove item from the database..."<<'\n'
                            <<"3.Exit program"<<'\n'
                            <<"4.Check how works system from user. This cause kick off with Admin settings"<<'\n'
                            <<"5.Change pass"<<'\n'
                            <<"6.Change login"<<'\n'
                            <<"7.Show yours login and pass"<<'\n'
                            <<"8.Browse user..."<<'\n'
                            <<"9.Reset pass and login to default..."<<'\n'
                            :
                std::cout
                            <<"0.Show details information about items..."<<'\n'
                            <<"1.Show buying items..."<<'\n'
                            <<"2.Log out"<<'\n'
                            <<"3.Exit program"<<'\n'
                            <<"4.Buy items"<<'\n';


    unsigned short y_D;

    while(!(std::cin>>y_D))
    {
        std::cout<<"Error value. Try again"<<'\n'<<std::flush;
        std::cin.clear();///rdstate to goodbit
        std::cin.sync();///clear with unnecessary character
    }
    // std::cout<<"3.Browse available items..."<<'\n';


    if(!decision_Admin && y_D >4) control_Panel(0,o);

    //if(y_D>8||y_D<=0){std::cout<<"Error! Unrecognized choice. Try again..."<<'\n';control_Panel(decision_Admin,o);}
    Files f1;
    Virtual_For_User * V_U;
    User u1;
    V_U=&u1;
    switch(y_D)
    {

case 0:
    {
    o->show_Info(o);
    break;
    }

    case 1:
    {
        if(!decision_Admin)
        {
         User u2;
    u2.load_User_Shopping();
        }
        else everything_Is_Good(1,o);
        break;
    }
    case 2:
    {
        if(!decision_Admin) V_U->log_Out();
        else everything_Is_Good(2,o);
        break;
    }
    case 3:
    {
        std::set_new_handler(error_Mem_Alloc);
        delete [] o;
        ///
        thanks_For_Use();

        break;
    }
    case 4:
    {
        o->buying_Item(o);
        break;
    }
    case 5:
    {


        f1.change_Password(o);
        break;
    }

    case 6:
    {

        f1.change_Login(o);
        break;
    }
    case 7:
    {
        f1.opening_Sesame(o,1);
        break;
    }
    case 8:
    {
        u1.base_Of_User(0,"","",o);
        break;
    }
    case 9:
    {
        f1.reset_To_Default(o);

        break;
    }

    default:
        exit(-1);
    }
    control_Panel(decision_Admin,o);

}

void remove_Item(list_Of_Ours_Product*&);
void everything_Is_Good(unsigned short y_D,list_Of_Ours_Product *&o)
///void everything_Is_Good(unsigned short y_D)
{
    std::cout<<"Good decision"<<'\n';
    list_Of_Product(o);






    if(y_D==1)o->add_Item(o);

    if(y_D==2)
    {
        std::cout<<"Settings will save after again run\n"<<'\n';
        o->remove_Item(o);
    }
    if(y_D==5) o->buying_Item(o);

    ///Polymorphism

}
void list_Of_Product(list_Of_Ours_Product *&o)
{
    std::cout<<"Actually, we have: "<<Class_For_Static::num_Of_Product<<'\n';





    printf("%s","Exactly: \n ");

    std::cout<<Class_For_Static::list_Prod<<'\n';





}

void list_Of_Ours_Product::show_Info(const list_Of_Ours_Product o[])
{


    for(unsigned int i=0; i<Class_For_Static::num_Of_Product; i++)
    {

        std::cout<<i<<o[i].name<<'\n';
    }


    unsigned int which;
    std::cout<<"Which item showing information? "<<'\n';
    std::cin>>which;
    std::cout<<"_____________________________________________________\n";

    std::cout.flush();





    //std::cout<<"UWAGA: "<<o[6].name<<'\n';
    if(which<Class_For_Static::num_Of_Product&&which>=0)
        std::cout<<"Product: "<<o[which].name<<' '<<"price: "<<o[which].price<<'\n'
                 <<"In magazine we have: "<<o[which].how_Much<<'\n'
                 <<"Information: "<<o[which].info<<'\n';

    std::cout<<"_____________________________________________________\n";


}


bool validationTest(float &);
bool validationTest( int &);///I know, that template was be a simpler than this, but i template debugging is horrible


void list_Of_Ours_Product::add_Item(list_Of_Ours_Product *&o)///CREATE THIS

{

    mem_Allocation(o);

   // std::cout<<" allocation: "<<o[0].name;
    Class_For_Static::num_Of_Product++;
    std::string name_Product;///Char is single character

    std::cout<<"_____________________________________________________\n";

    std::cout<<"Name yours item: "<<'\n';
    std::cin.ignore();




    std::cin>>name_Product;
    // while(validationTest(std::cin)==false);

    while(std::cin.fail())
    {
        std::cin.ignore();
        std::cin.sync();
        std::cin.clear();
        std::cin>>name_Product;
    }



    std::string tmp;
    sprintf((char*)tmp.c_str(), "%d", Class_For_Static::num_Of_Product);
    std::string str = tmp.c_str();
    tmp=str;
    tmp+=".";

    //std::cout<<"Before"<<"\n\n\n\n\n\n\n\n\n\n\n\n";

    tmp+=name_Product;
    tmp+=' ';


    ///list_Of_Ours_Product l[Class_For_Static::num_Of_Product];
    Class_For_Static::list_Prod+=tmp;
    Class_For_Static::list_Prod+='\n';






    std::cout<<"Okay, now write price..."<<'\n';


    Class_For_Static::el_Used++;
    Class_For_Static::used++;











    o[Class_For_Static::num_Of_Product-1].name=name_Product;

    //std::cin.ignore();
    float price_Product;

    validationTest(price_Product);




    o[Class_For_Static::num_Of_Product-1].price=static_cast<int>(price_Product)*100;///in pennies

    printf("%s","\nNow, write number of this item: \n");
    int number_Product;

    validationTest(number_Product);


    std::cout<<"Number: "<<number_Product<<'\n';

    o[Class_For_Static::num_Of_Product-1].how_Much=number_Product;
    std::cin.ignore();

    std::cout<<"Now write information about this item..."<<'\n';
    std::cout<<std::endl;
    std::string addition_Information;
    std::getline(std::cin,addition_Information);
    o[Class_For_Static::num_Of_Product-1].info=addition_Information;

    save::saving(SERIAL_BASE,name_Product,1);
    std::string temporarity_From_Int_Saving;
    std::string temp_From_Float_And_Int;
    temporarity_From_Int_Saving=std::to_string(Class_For_Static::num_Of_Product);
    temp_From_Float_And_Int=std::to_string(o[Class_For_Static::num_Of_Product-1].price);
    save::saving(name_Product,temp_From_Float_And_Int);
    temp_From_Float_And_Int=std::to_string(o[Class_For_Static::num_Of_Product-1].how_Much);
    save::saving(name_Product,temp_From_Float_And_Int);
    save::saving(name_Product,o[Class_For_Static::num_Of_Product-1].info);

    o->show_Info(o);



    control_Panel(1,o);

}
bool validationTest( int &l )
{
    do
    {


        std::cin >> l;


        if(std::cin.fail())
        {


            std::cout<<"Unrecognized value! Try again..."<<'\n';


            //std::cin.rdstate() to std::ios_base::goodbit
            std::cin.clear();

            // Ignoring charset after new line
            using Limits = std::numeric_limits<std::streamsize>;
            std::cin.ignore(Limits::max(), '\n');


        }
        else
        {

            break;

        }


    }
    while(true);





    if(l==0)
    {
        std::cout<<"Try again... Can't device by zero!"<<'\n';
        validationTest(l);

    }
    else if(l<0)
    {
        printf("%s","Ur value was change to absolute...\n");
        l=abs(l);
    }



    return true;
}
bool validationTest(float &l )
{
    do
    {


        std::cin >> l;


        if(std::cin.fail())
        {
            std::cout<<"Unrecognized value! Try again..."<<'\n';

            std::cin.clear();


            using Limits = std::numeric_limits<std::streamsize>;
            std::cin.ignore(Limits::max(), '\n');

        }
        else
        {

            break;

        }


    }
    while(true);
    if(l==0)
    {
        std::cout<<"Try again...This operation is not save..."<<'\n';
        validationTest(l);

    }
    else if(l<0)
    {
        printf("%s","Ur value was change to absolute...\n");
        l=abs(l);
    }
    return true;
}
void list_Of_Ours_Product::remove_Item(list_Of_Ours_Product *&o)
{



    Class_For_Static::used--;

    o->show_Info(o);





    list_Of_Product(o);
    std::string which;
    using std::endl;
    std::cout<<endl;
    std::cout<<"Which item delete? "<<'\n';
    std::cin>>which;



    int temp_For_Int=std::stoi(which);

    std::ifstream ff;
    ff.open(SERIAL_BASE,std::ifstream::in);
    std::string where_Going;
    int number_Line=1;
    std::string saving_A_String="";
    bool write_Or_No=true;
    while(std::getline(ff,where_Going))
    {
        switch(number_Line)
        {
        default:
            {
                write_Or_No=true;
                if(where_Going==o[temp_For_Int].name)
                {

                    int decision=0;
                    std::cout<<"Are you sure, that you can delete a: "<<where_Going<<" ?"<<'\n';
                    std::cout<<"Press 2, to refuse, 1 to accept: "<<'\n';
                    validationTest(decision);
                    if(decision==2)
                    {
                        ff.close();
                        return;
                    }
                    if(decision==1)
                    {
                        where_Going+=".bin";
                       if(std::remove(where_Going.c_str())!=0)
                       perror("Can't remove file...\n");
                       else
                       {
                           write_Or_No=false;
                           std::cout<<"Everything is good"<<'\n';
                       }
                    }
                    else
                    {

                        std::cout<<"Try again..."<<'\n';
                        o->remove_Item(o);
                    }

                }

                write_Or_No==true?saving_A_String+=where_Going:saving_A_String+'\n';

            }
        }
    }


    std::cout<<"Saving a string equal: "<<saving_A_String<<'\n';


    ff.close();
    std::ofstream again_Saving;
    again_Saving.open(SERIAL_BASE,std::ofstream::out);

    again_Saving<<saving_A_String<<'\n';

    again_Saving.close();

    /*
    size_t position=Class_For_Static::list_Prod.find(which);

    //std::cout<<"UWAGA: "<<position<<'\n';
    //std::cout<<"UWAGA: "<<Class_For_Static::list_Prod<<'\n';

    if(std::string::npos!=position)
        std::cout<<"Found in: "<<position<<'\n';
    else
    {
        std::cout<<"No item..."<<'\n';
        remove_Item(o);
    }
    for(unsigned int i=position; i<Class_For_Static::list_Prod.length(); i++)
    {
        if(isdigit(Class_For_Static::list_Prod[i])==false)
        {
            for(unsigned int j=i; j<Class_For_Static::list_Prod.length(); j++)
            {


                if(isdigit(Class_For_Static::list_Prod[j])==true || (j+1)==Class_For_Static::list_Prod.length())
                {
                    std::cout<<"\nj-> "<<j<<Class_For_Static::list_Prod.erase(position,j-position);
                    break;
                }
            }
            break;
        }

    }

    std::cout<<"WARRING: "<<'\n';
    int who=std::atoi(which.c_str());


    std::cout<<" if you can back, write number,smaller than 0"<<'\n';


    validationTest(who);
    if(who<0)control_Panel(1,o);

    std::cout<<"WHO: "<<who<<'\n';
    if(!(o->test(who)))control_Panel(1,o);///I know, that clever pointer don't need control, but REMEMBER NEVER TRUST A POINTER
    o[who].deleting_Item();



    std::cout<<"Iteration full: "<<Class_For_Static::list_Prod<<endl;
    Class_For_Static::el_Used=ile;
    control_Panel(1,o);
*/
}



int main()
{

    /* Problem

    *

    *

    *



    *
    *

    */



    Class_For_Static::actual_User="Admin_Test";





    list_Of_Ours_Product *false_Pointer;
    false_Pointer=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];
    Special_For_User s1;
    s1.open_From_Buying_Item(false_Pointer,0);
    delete [] false_Pointer;
    list_Of_Ours_Product *real_Pointer;
    real_Pointer=new list_Of_Ours_Product[Class_For_Static::num_Of_Product+1];
    s1.open_From_Buying_Item(real_Pointer,1);
    User u1;
    u1.base_Of_User(0,"","",real_Pointer);

    int decision;
    std::cout<<"Welcome in our base! "<<'\n';
    std::cout<<"Register, enter 1"<<'\n';
    std::cout<<"Sign in, enter 2"<<'\n';
    std::cout<<"No one ! I'll exit! Press 3"<<'\n';
    validationTest(decision);



    Virtual_For_User *V_U=nullptr;
    User uS;
    V_U=&uS;

    if(decision==2)
    {
        std::cout<<"Press 1 if can Login as user, or 2 as Administrator "
                 <<'\n';

        validationTest(decision);
        if(decision>2 || decision<1)validationTest(decision);
        Admin a1;
        decision==1?V_U->login_For_User(real_Pointer):a1.login_Of_Administator(real_Pointer);

        //  V_U->login_For_User()==true?control_Panel(1,l):control_Panel(0,l);
    }
    else if(decision==1)V_U->registration(real_Pointer);
    else if(decision==3)exit(0);
    else
    {
        printf("%s","Unrecognized value... Try again.\n");
        std::cout.flush();
        delete [] real_Pointer;///After delete
        main();
    }


    //delete [] l;
    //cout << "Hello world!" << endl;
    return 0;
}
void controler_Panel(int*defin(int))
{

}

void list_Of_Ours_Product::buying_Item( list_Of_Ours_Product *&o)
{
    if(Class_For_Static::num_Of_Product>0)
    {
        list_Of_Product(o);
        std::cout.flags();



        std::cout<<"List of product: "<<'\n';
        for(unsigned int i=0;i<Class_For_Static::num_Of_Product-1;i++)
            std::cout<<i<<'.'<<o[i].name<<'\n';

        std::cout<<"Which item would you like a buy ? Enter -1, to back"<<'\n';
        float *money=new float [1];

        money[0]=154.55;
        if(money[0]==0)money[0]=1;


        money[0]*=100;///in pennies

        unsigned int cash=static_cast<int>(money[0]);
        delete [] money;
        std::cout<<"Your money..."<<cash;


         int which=0;



        while(!(std::cin>>which))
        {
            std::cout<<"Unrecognized value..."<<'\n'<<"Try again...\n";
            std::cin.ignore(100,'\n');
            std::cin.clear();
            std::cin.sync();
            std::cin>>which;
        }
        std::cout<<"_________________________________________________________________________\n";

        if(which==-1)control_Panel(0,o);

        if(!(o->test(which)))o->buying_Item(o);

        std::cout<<"Price: "<<o[which].price<<'\n'<<
                 "Name: "<<o[which].name<<'\n'
                 <<"Quantity: "<<o[which].how_Much<<'\n'///Quantity->Ilosc
                 <<"Addition info: "<<o[which].info<<'\n';

                 std::cout<<"_________________________________________________________________________\n";

        printf("%s,%s,%s","\nBuying? Press 1","\nSelect another product? Press 2 ","\nBack? Press 3");

        unsigned int choose;
        std::cin>>choose;

        choose<1||choose>3?buying_Item(o):(void)choose;

        if((cash>=o[which].price)&&(choose==1) && (o[which].how_Much>0))
        {
            unsigned int h_Much
            ,h_Much_Can_Buy;///camelCase
            if(o[which].price>0) h_Much_Can_Buy=std::floor(cash/o[which].price);
            std::cout<<"You can buy: "<<h_Much_Can_Buy<<'\n';


            std::cout<<"Please wait..."<<'\n';
            std::cout.flush();///This should help with usleep
            std::cout<<"_________________________________________________________________________\n";
            std::cout<<"How many items could you buy ?";

            while(!(std::cin>>h_Much))
            {
                printf("%s","Try again");
                std::cout<<'\n'<<std::flush;
                std::cin.clear();
                std::cin.sync();
            }







            bool decision=false;
            std::cout<<"_________________________________________________________________________\n";
            std::cout<<"Are you sure buy ?"<<'\n';

            printf("%s","Press 1, to accept");
            while(!(std::cin>>decision))
            {
                printf("%s","Try again");
                std::cout<<'\n'<<std::flush;
                std::cin.clear();
                std::cin.sync();
            }
            if(h_Much_Can_Buy/h_Much>0 && o[which].how_Much<h_Much_Can_Buy && choose==1)
            {
                h_Much_Can_Buy/=h_Much;
                cash=(cash-((o[which].price)*(h_Much)));
                o[which].how_Much-=how_Much;
std::cout<<"_________________________________________________________________________\n";
                User u1;
                u1.save_Buying_Item(Class_For_Static::actual_User,o->name,h_Much);
                std::cout<<"cash-> "<<cash<<'\n'<<o[which].how_Much<<'\n';

            }

            else
            {

                std::cout<<"_________________________________________________________________________\n";

                printf("%s","Too many items or too small your money. Sorry, Zed is dead baby");

                o->buying_Item(o);
            }
            if(choose==2) o->buying_Item(o);




            o->buying_Item(o);

        }
    }
    else printf("%s,%s","Actually we don't have a item...","Maybe contact with Administrator? \n");


}
