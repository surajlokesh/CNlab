#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct node {
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int COST[20][20], no;
    // fstream inpf;
    // inpf.open("input.txt", ios::in);
    // if(inpf.is_open()){
    //     {
    //         for(int i=0;i<)
            

    //     }
    // }
    // inpf.close();

    cout << "Enter no of nodes." << endl;
    cin >> no;
    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < no; i++) {
        for (int j = 0; j < no; j++) {
            cin >> COST[i][j];
            COST[i][i] = 0;
            route[i].dist[j] = COST[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do {
        flag = 0;
        for (int i = 0; i < no; i++) {
            for (int j = 0; j < no; j++) {
                for (int k = 0; k < no; k++) {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j])) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++) {
        cout << "Node number: " << i + 1 << endl;
        cout << "Destination\tVia\tDistance" << endl;
        for (int j = 0; j < no; j++)
            printf("%d\t\t%d\t\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
    }
    return 0;
}