#include<bits/stdc++.h>
using namespace std;
int q[2000010] = {};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>q[i];
        }
        int dc = q[2]-q[1];
        cout<<dc;
        if(dc<0){
            dc = 0-dc;
        }
        if(d>=dc*2){
            long long dm = d/dc;
            long long ans = (n*3ll-dm*3ll+2ll)*(n*3ll-dm*3ll+3ll)/2;
            cout<<ans<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
}
