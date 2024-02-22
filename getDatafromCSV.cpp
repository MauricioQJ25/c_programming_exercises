#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

class Person{
public:
    std::string _name;
    int _birthyear;
    int _deadyear;
    
    Person(std::string name, int birthyear, int deadyear)
    : _name(name), _birthyear(birthyear), _deadyear(deadyear)
     {}
    ~Person(){}

    bool isAlive(int year){
        if( year >= _birthyear && year <= _deadyear){
            return true;
        }
        return false;
    }

    void printInfo(){
        std::cout << this->_name << " bd: " << this->_birthyear <<" dy:" << this-> _deadyear << std::endl;
    }
};


class Parser{
public:
    std::string _file;
    std::vector<Person> *_personsV;
    int _lowyear = 3000;
    int _highyear= 0;

    Parser(std::string file, std::vector<Person> *personsV){
        this->_file = file;
        this->_personsV = personsV;
    }

    void getData(){
        std::ifstream myfile;
        myfile.open(this->_file);
        std::string line = "";
        getline(myfile, line);
        line = "";
        std::string name;
        std::string birthyear;
        std::string deadyear;

        while(getline(myfile, line)){
            std::stringstream  templine(line);
            getline(templine, name, ',');
            getline(templine, birthyear, ',');
            getline(templine, deadyear, '\0');
            if(stoi(birthyear) < this->_lowyear){
                this->_lowyear = stoi(birthyear);
            }
            if(stoi(deadyear) > this->_highyear){
                this->_highyear = stoi(deadyear);
            }

            this->_personsV->push_back(Person(name, stoi(birthyear), stoi(deadyear)));
        }

    }


};

class PersonHandler{
public:
    std::vector<Person> *_personV;

    PersonHandler(std::vector<Person> *personV ){
        this->_personV = personV;
    }

    void printAllInfo(){
        for(auto it = this->_personV->begin(); it < this->_personV->end(); it++){
            it->printInfo();
        }
    }

    int counterAlive(int year){
        int counterAlive = 0;
        for(auto it = this->_personV->begin(); it < this->_personV->end(); it++){
            if(it->isAlive(year) == true){
                counterAlive++;
            }
        }
        return counterAlive;
    }
};


int main(int argc, char* arg[]){

    std::vector<Person> personsV;
    Parser parser = Parser("myfile.csv", &personsV);
    parser.getData();
    PersonHandler handler = PersonHandler(&personsV);
    handler.printAllInfo();
    //int counter = handler.counterAlive(1977);
    //std::cout << "persons alive in 1500: " << counter << std::endl;

    int lowyear = parser._lowyear;
    int highyear = parser._highyear;
    int maxYear = lowyear;
    int counterPrev = 0;
    int counterNew = 0;
    
    for (int i = lowyear; i <= highyear; i++){
        counterNew =  handler.counterAlive(i);
        if (counterNew > counterPrev){
            maxYear = i;
            counterPrev = counterNew;
        } 
    }

    std::cout << "Max year: " << maxYear << " persons alive " << counterPrev << std::endl; 
    return 0;
}