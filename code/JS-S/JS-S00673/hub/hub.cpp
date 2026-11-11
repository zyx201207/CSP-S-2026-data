#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
int t,n,k;
vector<int>vec[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>t>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
    }
    return 0;
}
