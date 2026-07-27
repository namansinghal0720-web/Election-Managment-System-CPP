#include "../include/Person.hpp"

Person::Person()
{
    id = 0;
    age = 0;
}

Person::Person(
    int id,
    const std::string& name,
    int age,
    const std::string& department
)
    :
    id(id),
    name(name),
    age(age),
    department(department)
{
}

int Person::getId() const
{
    return id;
}

const std::string& Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

const std::string& Person::getDepartment() const
{
    return department;
}

void Person::setName(const std::string& name)
{
    this->name = name;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setDepartment(const std::string& department)
{
    this->department = department;
}