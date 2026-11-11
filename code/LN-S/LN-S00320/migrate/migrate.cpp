#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    int a[1000000008];
    int b=0;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=0;j<=n;j++)
        {
            if(a[i]-a[i-1])
            {
                break;
            }
            b++;
        }
        if(b<2*d)
        {
            cout<<"0"<<endl;
        }if(b==2*d)
        {
            cout<<"1"<<endl;
        }else
        {
            cout<<b-2*d+1<<endl;
        }
    }
    return 0;
}
