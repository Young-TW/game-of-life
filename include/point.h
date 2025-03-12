#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point();
    Point(bool);
    void set(bool);
    bool get();

private:
    bool alive;
};

Point::Point() { this->set(false); }

Point::Point(bool status) { this->set(status); }

void Point::set(bool status) {
    this->alive = status;
    return;
}

bool Point::get() { return this->alive; }

#endif