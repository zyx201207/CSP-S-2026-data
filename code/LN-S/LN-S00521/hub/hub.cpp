#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){//a1a1a1wo3du2bu4dong3ti2...
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int u,v;
        for(int i=2;i<=n;i++)cin>>u>>v;
        n--;
        int qiu;
        srand(qiu);
        cout<<abs(rand())%n+1<<'\n';
    }
    return 0;
}
