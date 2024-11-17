#include "header.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

void saveToFile(const std::string& filename, const std::vector<std::string>& data){
    std::ofstream file;
    file.open(filename);
    
    if(!file.is_open()) return;

    for(auto string: data){
        file << string << std::endl;
    }
    file.close();
}

void loadFromFile(const std::string& filename, std::vector<std::string>& outData){
    std::ifstream file;
    file.open(filename);

    if(!file.is_open()) return;

    std::string string;
    while(std::getline(file, string)) outData.push_back(string);
}

void saveToFile(const std::string& filename, const std::vector<Book>& data){
    std::ofstream file;
    file.open(filename);
    
    if(!file.is_open()) return;

    for(auto book: data){
        file << book.Author << ";" << book.Title << ";" << book.Year << std::endl;
    }
    file.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData){
    std::ifstream file;
    file.open(filename);
    
    if(!file.is_open()) return;

    std::string str;
    while(std::getline(file, str)){
        int i1 = str.find(';');
        int i2 = str.find(';', i1+1);
        Book book;
        book.Author = str.substr(0, i1-1);
        book.Title = str.substr(i1+1, i2-i1-1);
        book.Year = std::stoi(str.substr(i2+1));
        outData.push_back(book);
    }
    file.close();
}


void saveToFile(const std::string& filename, Groups& groups){
    std::ofstream file;
    file.open(filename);
    if(!file.is_open()){
       return; 
    }
    for(auto group: groups){
        file << "group" << std::endl;
        file << group.first << std::endl;
        for(auto student:group.second){
            file << "student"<<std::endl;
            file << student.Name << std::endl;
            file << student.Year << std::endl;
            file << "books" << std::endl;

            for(auto book: student.RecordBook){
                file << "book" << std::endl;
                
                file << book.first << std::endl;
                file << book.second << std::endl;
            }
            file << "end_books" << std::endl;
            file << "end_student" << std::endl;
        }
        file << "end_group" << std::endl;
    }
    file.close();
}


void loadFromFile(const std::string& filename, Groups& groups){
    std::ifstream file;
    file.open(filename);
    std::string str;
    std::string group;
    Student stud;
    while(std::getline(file, str)){
        if(str=="group"){
            std::getline(file, str);
            group = str;
            continue;
        }
        if(str=="student"){
            std::getline(file, str);
            stud.Name = str;
            std::getline(file, str);
            stud.Year = std::stoi(str);
            continue;
        }
        if(str=="book"){
            std::getline(file, str);
            std::string name = str;
            std::getline(file, str);
            stud.RecordBook[name] = Score(std::stoi(str));
            continue;
        }
        if(str == "end_student"){
            groups[group].push_back(stud);
            stud.RecordBook.clear();
            continue;
        }
    }
    file.close();
}