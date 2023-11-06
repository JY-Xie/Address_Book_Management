#include <iostream>
#include "string"


const int max_person_number = 1000;
struct person{
    std::string name;
    int gender;
    int age;
    std::string phone_num;
    std::string addr;
};

struct address_book{
    int m_size;
    person people_array[max_person_number];
};

void show_menu();
void add_person(address_book *addressBook);
void show_person(address_book *addressBook);
int is_exist(address_book *addressBook, std::string name);
void delete_person(address_book *addressBook);
void find_person(address_book *addressBook);
void update_person(address_book *addressBook);
void clear_person(address_book *addressBook);

int main() {
    address_book addressBook;
    addressBook.m_size = 0;

    int select_num;
    while (1) {
        show_menu();
        std::cin >> select_num;

        switch (select_num) {
            case 1:
                add_person(&addressBook);
                break;
            case 2:
                show_person(&addressBook);
                break;
            case 3:
                delete_person(&addressBook);
                break;
            case 4:
                find_person(&addressBook);
                break;
            case 5:
                update_person(&addressBook);
                break;
            case 6:
                clear_person(&addressBook);
                break;
            default:
                std::cout << "Quit Now!";
                return 0;
        }
    }
}


void show_menu(){
    std::cout << "1. Add User" << std::endl;
    std::cout << "2. Show User" << std::endl;
    std::cout << "3. Delete User" << std::endl;
    std::cout << "4. Find User" << std::endl;
    std::cout << "5. Update User" << std::endl;
    std::cout << "6. Clear User" << std::endl;
    std::cout << "0. Quit" << std::endl;
}

void add_person(address_book * abs){
    if (abs->m_size == max_person_number){
        std::cout << "Address Book is Full!" << std::endl;
    } else {
        std::string name;
        std::cout << "Please input the name: " << std::endl;
        std::cin >> name;
        abs->people_array[abs->m_size].name = name;

        int gender = 0;
        std::cout << "Please input the gender: " << std::endl;
        std::cout << "1: male, 2:female: " << std::endl;
        while (1) {
            std::cin >> gender;
            if (gender == 1 || gender == 2){
                abs->people_array[abs->m_size].gender = gender;
                break;
            }
            std::cout << "input error, retry!" << std::endl;
        }

        int age = 0;
        std::cout << "Please input the age: " << std::endl;
        std::cin >> age;
        abs->people_array[abs->m_size].age = age;

        std::string phone;
        std::cout << "Please input the phone number: " << std::endl;
        std::cin >> phone;
        abs->people_array[abs->m_size].phone_num = phone;

        std::string address;
        std::cout << "Please input the address: " << std::endl;
        std::cin >> address;
        abs->people_array[abs->m_size].addr = address;

        abs->m_size++;
        std::cout << "Success!" << std::endl;
//        system("pause");
//        system("cls");
    }
}

void show_person(address_book * abs){
    if (abs->m_size == 0){
        std::cout << "The book is null" << std::endl;
    } else {
        for (int i = 0; i < abs->m_size; ++i) {
            std::cout << "name:" << abs->people_array[i].name << "\t";
            std::cout << "gender:" << ((abs->people_array[i].gender == 1) ? "male": "female") << "\t";
            std::cout << "age:" << abs->people_array[i].age << "\t";
            std::cout << "phone:" << abs->people_array[i].phone_num << "\t";
            std::cout << "address:" << abs->people_array[i].addr << std::endl;
        }
    }
//    system("pause");
//    system("cls");
}

int is_exist(address_book * abs, std::string name){
    for (int i = 0; i < abs->m_size; ++i) {
        if (abs->people_array[i].name == name){
            return i;
        }
    }
    return -1;
}

void delete_person(address_book * abs){
    std::cout << "Please input the name that you want to delete" << std::endl;
    std::string del_name;
    std::cin >> del_name;
    int ret = is_exist(abs, del_name);
    if (ret != -1){
        if (ret == abs->m_size-1){
            abs->people_array[ret] = {};
        }else{
            for (int i = ret; i < abs->m_size-1; ++i) {
                abs->people_array[i] = abs->people_array[i+1];
            }
            abs->m_size--;
            std::cout << "succeed in deleting" << std::endl;
        }
    }else{
        std::cout << "this person is not in address book" << std::endl;
    }
}

void find_person(address_book * abs){
    std::cout << "Please input the name that you want to find" << std::endl;
    std::string name;
    std::cin >> name;

    int ret = is_exist(abs, name);

    if (ret != 1){
        std::cout << "name: " << abs->people_array[ret].name << "\t";
        std::cout << "gender: " << abs->people_array[ret].gender << "\t";
        std::cout << "age: " << abs->people_array[ret].age << "\t";
        std::cout << "phone: " << abs->people_array[ret].phone_num << "\t";
        std::cout << "address: " << abs->people_array[ret].addr << std::endl;
    } else {
        std::cout << "this person is not in address book" << std::endl;
    }
}

void update_person(address_book * abs){
    std::cout << "Please input the name that you want to update" << std::endl;
    std::string name;
    std::cin >> name;
    int ret = is_exist(abs, name);
    if (ret != -1){
        std::string new_name;
        std::cout << "please input the new name" << std::endl;
        std::cin >> new_name;
        abs->people_array[ret].name = new_name;

        std::cout << "please input the new gender" << std::endl;
        std::cout << "1: male, 2: female" << std::endl;
        int sex = 0;
        std::cin >> sex;
        while (1){
            std::cin >> sex;
            if (sex == 1 || sex == 2){
                abs->people_array[ret].gender = sex;
                break;
            }
            std::cout << "input error, retry!" << std::endl;
        }

        std::cout << "please input the new age" << std::endl;
        int age = 0;
        std::cin >> age;
        abs->people_array[ret].age = age;

        std::cout << "please input the new tel" << std::endl;
        std::string tel;
        std::cin >> tel;
        abs->people_array[ret].phone_num = tel;

        std::cout << "please input the new address" << std::endl;
        std::string address;
        std::cin >> address;
        abs->people_array[ret].addr = address;
    } else {
        std::cout << "this person is not in address book" << std::endl;
    }
}

void clear_person(address_book * abs){
    abs->m_size = 0;
    std::cout << "The address book is already null" << std::endl;
    system("pause");
    system("cls");
}