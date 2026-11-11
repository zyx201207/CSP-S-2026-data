#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN1=500010,maxN2=510;
struct Node{
    int a,t;
};
vector<Node> s[maxN2];
vector<Node> dd[maxN1];
int c,n,m,d,q,w[maxN1],k[maxN2],aa[maxN1],ans,x,y;
void dfs(int xx){
    if(xx==y){
        ans=min(aa[xx]+w[xx],ans);
        return;
    }
    for(int i=0;i<dd[xx].size();i++){
        for(int j=0;j<s[dd[xx][i].a].size();j++){
            //cout<<"try "<<s[dd[xx][i].a][j].a<<" from "<<xx<<endl;
            if(((dd[s[dd[xx][i].a][j].a].size()==1||(aa[s[dd[xx][i].a][j].a]<=aa[xx]+dd[xx][i].t+s[dd[xx][i].a][j].t&&aa[s[dd[xx][i].a][j].a]!=0))&&s[dd[xx][i].a][j].a!=y||s[dd[xx][i].a][j].a==xx)){
                //cout<<"No,because "<<(dd[s[dd[xx][i].a][j].a].size()==1)<<(aa[s[dd[xx][i].a][j].a]<=aa[xx]+dd[xx][i].t+s[dd[xx][i].a][j].t)<<(aa[s[dd[xx][i].a][j].a]!=0)<<(s[dd[xx][i].a][j].a!=y)<<(s[dd[xx][i].a][j].a==xx)<<endl;
                continue;
            }
            aa[s[dd[xx][i].a][j].a]=s[dd[xx][i].a][j].t+aa[xx]+dd[xx][i].t;
            //cout<<"from "<<xx<<" to "<<s[dd[xx][i].a][j].a<<endl;
            dfs(s[dd[xx][i].a][j].a);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        Node in;
        for(int j=1;j<=k[i];j++){
            cin>>in.a>>in.t;
            s[i].push_back(in);
            Node ii=in;
            ii.a=i;
            dd[in.a].push_back(ii);
        }
    }
    for(;q>0;q--){
        ans=1e18;
        cin>>x>>y;
        for(int i=1;i<=m;i++) aa[i]=0;
        aa[x]=w[x];
        dfs(x);
        cout<<ans<<endl;
    }
    return 0;
}
//!?qinagqiang?!//