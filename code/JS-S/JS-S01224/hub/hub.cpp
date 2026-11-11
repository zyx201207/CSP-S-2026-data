/*buhui pianfen <=0pts*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,deg[1000001]={},c,t,k;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int cnt=0;
        for(int i=1;i<=n;i++)deg[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        for(int i=1;i<=n;i++){
            if(deg[i]==1)cnt++;
        }
        int tt=(n-k)/(cnt+1);
        if(tt*(cnt+1)<(n-k))tt++;
        cout<<tt<<endl;
    }
    return 0;
}