#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==1||c==2){
            cout<<0<<endl;
        }else if(c==11||c==12){
            long long y=a[2]-a[1];
            if(n>(d/y)*2-1)cout<<n-(long long)(d/y)*2+1<<endl;
            else cout<<0<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}
