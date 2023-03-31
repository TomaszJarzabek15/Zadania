#include <iostream>
using namespace std;

struct LIST_STRUCT {
    int info;
    LIST_STRUCT* next;
};

void DisplayList(LIST_STRUCT* firstElem){
    for ( LIST_STRUCT* walkElem = firstElem; walkElem != NULL; walkElem = walkElem->next ){
        cout << walkElem->info << endl;
    }
}

void AddFirst(LIST_STRUCT** firstElem, LIST_STRUCT* newElem){         //Dodanie węzła na początek listy

    newElem->next = *firstElem;
    *firstElem = newElem;
}

void AddLast(LIST_STRUCT* firstElem, LIST_STRUCT* newElem){        //Dodanie węzła na koniec list.
    
    LIST_STRUCT* walkElem = firstElem;

    while(walkElem->next != NULL){
        walkElem = walkElem->next;
    }

    walkElem->next = newElem;
    newElem->next = NULL;
}

void AddPrevious(LIST_STRUCT** firstElem, LIST_STRUCT* newElem, LIST_STRUCT* currElem){     //Dodanie węzła przed wskazywanym węzłem

    LIST_STRUCT* walkElem = *firstElem;

    if(walkElem == currElem){
        AddFirst(firstElem, newElem);
    }
    else{

        while(walkElem->next != currElem){
            walkElem = walkElem->next;
        }
        
        newElem->next = currElem;
        walkElem->next = newElem;
    }
}

void AddNext(LIST_STRUCT* firstElem, LIST_STRUCT* newElem, LIST_STRUCT* currElem){      //Dodanie węzła po wskazywanym węźle

    if(currElem->next == NULL){
        currElem->next = newElem;
        newElem->next = NULL;
    }
    else{
        newElem->next = currElem->next;
        currElem->next = newElem;
    }
}

void DeleteFirst(LIST_STRUCT** firstElem){      //Usuwamy pierwszy element listy

    LIST_STRUCT* SaveNext = (*firstElem)->next;
    delete *firstElem;
    *firstElem = SaveNext;
}

void DeleteLast(LIST_STRUCT* firstElem){        //Usunięcie ostatniego węzła.

    LIST_STRUCT* walkElem = firstElem;

    while(walkElem->next->next != NULL){
        walkElem = walkElem->next;
    }

    LIST_STRUCT* SaveNext = walkElem->next;
    delete SaveNext;
    walkElem->next = NULL;
}

void DeleteNext(LIST_STRUCT* currElem){     //Usunięcie węzła po wskazywanym węźle.

    if(currElem->next != NULL){
        LIST_STRUCT* SaveNext = currElem->next->next;
        delete currElem->next;
        currElem->next = SaveNext;
    }
}

void DeletePrevious(LIST_STRUCT** firstElem, LIST_STRUCT* currElem){

    LIST_STRUCT* walkElem = *firstElem;

    if(walkElem == currElem){
        //nic nie robimy bo kasujemy za
    }
    else if(walkElem->next == currElem){
        DeleteFirst(firstElem);
    }
    else{

        while(walkElem->next->next != currElem){
            walkElem = walkElem->next;
        }

        LIST_STRUCT* SaveNext = walkElem->next->next;
        delete walkElem->next;
        walkElem->next = SaveNext;
    }
}

void DeleteCurrent(LIST_STRUCT** firstElem, LIST_STRUCT* currElem){       //Usunięcie wskazywanego wezła.

    LIST_STRUCT* walkElem = *firstElem;

    if(walkElem == currElem){       //usuwamy pierwszy element listy
        DeleteFirst(firstElem);
    }
    else{
        while(walkElem->next != currElem){
            walkElem = walkElem->next;
        }

        if(walkElem->next != NULL){
            LIST_STRUCT* SaveNext = walkElem->next->next;
            delete walkElem->next;
            walkElem->next = SaveNext;
        }
    }
}


int main() {

    LIST_STRUCT* firstElem = NULL;

    int buf;

    do {
        cin >> buf;
        if (buf == 0 ){
            break;
        }

        LIST_STRUCT* newElem = new LIST_STRUCT;

        newElem->info = buf;
        newElem->next = firstElem;
        firstElem = newElem;
    }while ( true );

    DisplayList(firstElem);
    cout << "------------------------" << endl;

    LIST_STRUCT* currentElem = firstElem;

    //DeleteNext(currentElem);
    
    //DeleteCurrent(&firstElem, currentElem);

    //DeleteFirst(&firstElem);

    //DeleteLast(firstElem);

    //DeletePrevious(&firstElem, currentElem);

    cin >> buf;
    cout << "--------------" << endl;

    LIST_STRUCT* newElem = new LIST_STRUCT;

    newElem->info = buf;

    //AddFirst(&firstElem, newElem);

    //AddLast(firstElem, newElem);

    //AddPrevious(&firstElem, newElem, currentElem);

    AddNext(firstElem, newElem, currentElem);

    DisplayList(firstElem);
    cout << "------------------------" << endl;



    return 0;
}