#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person
{
protected:
    int id;
    std::string name;
    int age;
    std::string department;

public:

    Person();

    Person(
        int id,
        const std::string& name,
        int age,
        const std::string& department
    );

    virtual ~Person() = default;

    int getId() const;

    const std::string& getName() const;

    int getAge() const;

    const std::string& getDepartment() const;

    void setName(const std::string& name);

    void setAge(int age);

    void setDepartment(const std::string& department);

    virtual void display() const = 0;
};

#endif