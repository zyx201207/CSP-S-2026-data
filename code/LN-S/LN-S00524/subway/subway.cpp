// this is NO.2 : subway  
#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct chzhan{int zhan;int yongshi;};
vector<vector<chzhan>>at;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<chzhan> kat(k);
        for(int i=1;i<=k;i++){
            cin>>kat[i].zhan>>kat[i].yongshi;
        }
        at.push_back(kat)
    }
    while(q--){
        int st,en;
        cin>>st>>en;
        int ans=w[st]+w[en];
        cout<<ans<<endl;
    }
    return 0;
}