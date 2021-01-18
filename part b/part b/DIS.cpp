#include<bits/stdc++.h>
using namespace std;
struct node
{
    unsigned d[50];
    unsigned f[50];
}rt[25];
int main()
{
    int cm[50][50];
    int n,i,j,k,couant=0;
    cout<<"\nEnter the number of nodes : ";
    cin>>n;               //Enter the nodes
    cout<<"\nEnter the cost matrix :\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>cm[i][j];
            cm[i][i]=0;
            rt[i].d[j]=cm[i][j];
            rt[i].f[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(rt[i].d[j]>cm[i][k]+rt[k].d[j])
                {
                    rt[i].d[j]=rt[i].d[k]+rt[k].d[j];
                    rt[i].f[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<n;i++)
        {
            cout<<"\n\n For router \n"<< i+1;
            for(j=0;j<n;j++)
            {
                cout<<"\t\nnode "<<j+1<<" hop "<<  rt[i].f[j]+1<<" Distance "<<rt[i].d[j];
            }
        }
    cout<<endl;
    //getch();
}