#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d[2000005],i,j;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>a;
    for(i=1;i<=a;i++)
    {
        cin>>b>>c;
        for(j=1;j<=b;j++)
        {
            cin>>d[i];
        }
        if(d[3]-d[1]>c)
        {
            cout<<"0"<<endl;
            continue;
        }
        cout<<b-3<<endl;
    }
    return 0;
}
