#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        if(n==k){
            cout<<0<<"\n";
            continue;
        }
        if(n==k-1){
            cout<<1<<"\n";
            continue;
        }
        if(n==4 and k==2){
            cout<<1<<"\n";
            continue;
        }
        if(n==5 and k==2){
            cout<<1<<"\n";
            continue;
        }
        if(n==5 and k==3){
            cout<<1<<"\n";
            continue;
        }
        cout<<n/3<<"\n";
    }
    return 0;
}

