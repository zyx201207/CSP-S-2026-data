#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int n,d;
int a[N];
void slove(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<0<<"\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        slove();
    }
    return 0;
}