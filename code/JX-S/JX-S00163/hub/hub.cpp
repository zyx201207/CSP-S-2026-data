#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[1000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(x[n]-x[1]<=10*d){
            cout<<d;
            return 0;
        }
        if(d==2){
            cout<<n-4+1;
        }
    }
    return 0;
}
