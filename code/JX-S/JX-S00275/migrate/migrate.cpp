#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t
    while(t--){
        cin>>n>>d;int a[1e5+5];
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            if(i==1||x-a[i-1]<=d) a[i]=x;

        }
        if(2*d-1==a[n]-a[1]) cout<<1;
        else if(2*d-1>a[n]-a[i]) cout<<0;
        else{
            cout<<2*d-1-(a[n]-a[i])+1;
        }
    }
    return 0;
}