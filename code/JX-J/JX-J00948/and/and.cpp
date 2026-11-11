#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x=0,y=0;
    string a,b;
    cin>>n>>m;
    for (int i = 1;i <= n;i++)
    {
        cin>>a;
        b+=a;
    }
    for(int i = 0;i<n;i++)
    {
        for (int j = 0;j<i;j++)
            x=b[i] && b[j];
            if (x > y)
        {
            y=x;
        }
    }
    cout<<y;
    return 0;
}
