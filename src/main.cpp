#include "header.hpp"
#include <iostream>


int main(){
    std::vector<std::string> data = {"hello", "can", "do it"};
    std::vector<std::string> input_data;
    saveToFile("file.txt", data);
    loadFromFile("file.txt",  input_data);
    for(auto i: input_data) std::cout << i << ", ";
    std::cout << std::endl;
    Book book1;
    book1.Author = "Dante";
    book1.Title = "The Divine Comedy";
    book1.Year = 1308;

    Book book2;
    book2.Author = "Shakespeare";
    book2.Title = "Romeo and Juliet";
    book2.Year = 1595;

    std::vector<Book> books = {book1, book2};
    std::vector<Book> input_books;
    saveToFile("books.txt", books);
    loadFromFile("books.txt", input_books);
    for(auto book: input_books){
        std::cout << book.Author << " " << book.Title << " " << book.Year << ",";
    }
    std::cout << std::endl;

    Student student1;
    student1.Name = "Anton";
    student1.Year = 2005;
    student1.RecordBook["math"] = Excellent;
    student1.RecordBook["history"] = Satisfactorily;
    
    Student student2;
    student2.Name = "Savva";
    student2.Year = 2003;
    student2.RecordBook["math"] = Good;
    student2.RecordBook["history"] = Excellent;

    Student student3;
    student3.Name = "Ilya";
    student3.Year = 2007;
    student3.RecordBook["matanalis"] = Good;
    student3.RecordBook["history"] = Excellent;

    Student student4;
    student4.Name = "Ivan";
    student4.Year = 2007;
    student4.RecordBook["matanalis"] = Excellent;
    student4.RecordBook["history"] = Excellent;

    Groups groups;
    groups["MT10-11"] = {student1, student2};
    groups["IU8-12"] = {student2, student3};

    saveToFile("students.txt", groups);

    Groups input_group;
    loadFromFile("students.txt", input_group);
    saveToFile("input_studetns.txt" ,input_group);

    return 0;
}