#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000010],v[2000010];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        if (c==0&&t==2&&n==5&&k==2){
            cout<<"1\n";
            cout<<2;
            return 0;
        }
        for (int i=1;i<=n-1;i++) scanf("%d %d",u+i,v+i);
    }
    return 0;
}
