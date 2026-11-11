#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<0<<'\n';
            continue;
        }
        if((a[n-1]-a[n-2])>=d){ cout<<0<<'\n';
        }else{
            cout<<n-(d/(a[n-1]-a[n-2])*2)+1<<'\n';
        }
    }
    return 0;
}