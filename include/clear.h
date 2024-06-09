#ifndef CLEAR_H
#define CLEAR_H

void clear() {
#ifdef __GNUC__
    system("clear");
#elif defined _MSC_VER
    system("cls");
#endif
    return;
}

#endif