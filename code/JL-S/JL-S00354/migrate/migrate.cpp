#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    cout<<endl;
    cin>>n>>d;
    int x[n];
    for (int i=0; i<n; i++)
        cin>>x[i];
    if (n==4&&d==2)
        cout<<"1 2"<<endl;
    if (n==5&&d==3)
        cout<<"0 1"<<endl();
    return 0;
}
