#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int c,t,n,k,fa[N],lay[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            fa[v]=u;
            if(i==1) lay[u]=1;
            lay[v]=lay[u]+1;
        }
        if(k%2==0) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}

