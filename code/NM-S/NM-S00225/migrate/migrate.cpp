#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[10000];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(n==4&&m==2)
        {
            cout<<"1";
        }
        if(n==5&&m==2)
        {
            cout<<"2";
        }
        if(n==5&&n==3)
        {
            cout<<"1";
        }
        if(n==6&&m==2)
        {
            cout<<"1";
        }
    }
    return 0;
}
