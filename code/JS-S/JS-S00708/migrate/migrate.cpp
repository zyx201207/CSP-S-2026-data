#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int cnt=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n-3;i++)
        {
            if(a[i+3]-a[i]>d) cnt++;
        }
        cout<<cnt<<endl;
    }
}
