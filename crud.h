#ifndef CRUD_H
#define CRUD_H


#pragma once
#include <vector>
using namespace std;

/**
* CREATE, READ, UPDATE, DELETE
* CRUD operations repository interface
*/
template <class E>
class CrudRepository {
public:

    virtual int findOne(int id) = 0;

    virtual const vector<E>& getAll() = 0;

    virtual void save(const E& entity) = 0;

    virtual void del(int id) = 0;

    virtual void update(const E& entity) = 0;

    virtual ~CrudRepository() {};
};

#endif // CRUD_H
