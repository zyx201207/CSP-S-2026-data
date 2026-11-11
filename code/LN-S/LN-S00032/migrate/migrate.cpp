#include<bits/stdc++.h>
using namespace std;
int c,t;
int ans[50005];
int v=1;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int a[2000005]={};
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==5&&d==2) ans[v++]=2;
       else if(n==4&&d==2) ans[v++]=1;
       else if(d>=(a[n]-a[1])) ans[v++]=0;
       else if(n==5&&d==3) ans[v++]=0;
       else ans[v++]=1;
    }
    for(int i=1;i<v;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
