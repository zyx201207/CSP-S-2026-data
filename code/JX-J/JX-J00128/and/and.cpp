#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[200005]={};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(m==n)
    {
        cout<<a[i];
    }

    }
    if(m==2)
    {
       sort(a,a+n);
    }
    double h=2;
    for(int i=0;i<31;i++)
    {
        h=h*2;
    }
    if(h>1000000000)
    {
        cout<<"a";
    }
    return 0;
}
