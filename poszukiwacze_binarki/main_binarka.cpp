#include "riddle.h"
using namespace std;
int main(){
    Riddle& memory = Riddle::winarium();
    int id = 1; // id 0, 1 są zawsze dostępne, inne wymagają wiekszej wartosi N_i na wejściu
    memory.akcio(id);
    memory(id).info = 123;
    Crux& item = memory(id);
    cout << item.info << endl;
    memory.evanesko(id);
    Riddle::levioooza();
    return 0;
}