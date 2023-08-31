#pragma once

template <typename T>
class ITransporter {
public:
    virtual void load(const T& item) = 0;
    virtual void unload() = 0;
    virtual void empty() = 0;
    virtual void move() = 0;
    virtual bool isEmpty() const = 0;
    virtual int itemCount() const = 0;
    virtual ~ITransporter() {}
};