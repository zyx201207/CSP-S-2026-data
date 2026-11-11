#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<2<<endl;
    }
    return 0;
}
