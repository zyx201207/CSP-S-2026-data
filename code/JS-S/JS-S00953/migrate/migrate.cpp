#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long d;
        cin>>n>>d;
        long long a[2000005];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long gongcha=a[1]-a[0];
        long long len=2*d-1;
        if(len%gongcha!=0||a[0]+len>a[n-1])
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            cout<<(a[n-1]-a[0]-len)/gongcha+1<<endl;
            continue;
        }
    }
    return 0;
}
