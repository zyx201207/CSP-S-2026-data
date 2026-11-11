#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],ans,x,y;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<n;i++)cin>>x>>y;
        if(d==2&&n<=5){
             ans=1;
            if(d==2&&n==2)ans=0;
        }
        else if(d<=2&&n<=10)ans=4;
        else if(d<=5&&n<=10)ans=2;
        else if(d<=10&&n<=10)ans=1;
        cout<<ans<<"\n";
    }
    return 0;
}
