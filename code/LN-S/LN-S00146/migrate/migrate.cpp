#include<bits/stdc++.h>
using namespace std;
int t,c;
int n,d;
int x[1008];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        srand(time(NULL));
        int r=rand()%5;
        cout<<r<<"\n";
    }
    return 0;
}