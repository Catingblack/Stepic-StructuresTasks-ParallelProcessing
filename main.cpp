#include <iostream>
#include <queue>

using namespace std;

void printMass(int* Arr, int n) {
    for(int i =0 ; i < n; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}


void readMass(int* Arr, int n) {
    for(int i = 0; i < n; i++) {
        cin >> Arr[i];
    }
}

int Prnt(int i) {
    return (i - 1) / 2;
}

int LCh(int i) {
    return (2 * i) + 1;
}

int RCh(int i) {
    return (2 * i) + 2;
}

void Turn(int* Arr, int i, int j) {
    int x;
    x = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = x;
}


void SiftDown(int* Arr, int* iArr, int n, int i) {

    int j;

    while(i < n/2) {
        j = i;

        if( Arr[RCh(i)] < Arr[i] and RCh(i) < n ) {
            j = RCh(i);
        }

        if( Arr[LCh(i)] < Arr[j] and LCh(i) < n) {
            j = LCh(i);
        }

        if(j == i) {
            break;
        }

        Turn(Arr, i, j);
        Turn(iArr, i, j);

        i = j;

        if( Arr[LCh(i)] > Arr[RCh(i)] and RCh(i) < n ) {
            Turn(Arr, LCh(i), RCh(i));
        }
    }
}

void SiftDownT(int* Arr, int* iArr, int n, int i) {

    int j;

    while(i < n/2) {
        j = i;

        if( iArr[RCh(i)] < iArr[i] and RCh(i) < n ) {
            if( Arr[i] == Arr[RCh(i)] ) {
                j = RCh(i);
            }
        }

        if( iArr[LCh(i)] < iArr[j] and LCh(i) < n) {
            if( Arr[i] == Arr[LCh(i)] ) {
                j = LCh(i);
            }
        }

        if(j == i) {
            break;
        }

        Turn(iArr, i, j);

        i = j;

    }
}


void BuildHeap(int* Arr, int* iArr, int n) {


    for(int i = (n/2 - 1); i >= 0; i--) {  // Построение кучи по времени выполнения
        SiftDownT(Arr, iArr, n, i);
    }

}


int main()
{

    int n, m;

    int* Arr; // Мин куча процессоров
    int* iArr; // Номера процессоров
    int* tArr; // Время выполнения задач

    cin >> n; // Количество процессоров
    cin >> m; // Количество задач

    tArr = new int[m];
    Arr = new int[n];
    iArr = new int[n];

    for(int i = 0; i < n; i++) {
        iArr[i] = i;
        Arr[i] = 0;
    }

    readMass(tArr, m);

    cout << endl;
    for(int i = 0; i < m; i++) {
        cout << iArr[0] << " " << Arr[0] << endl;
        Arr[0] = Arr[0] + tArr[i];
        SiftDown(Arr, iArr, n, 0);
        BuildHeap(Arr, iArr, n);
    }




    delete [] tArr;
    delete [] Arr;
    delete [] iArr;

    return 0;
}
