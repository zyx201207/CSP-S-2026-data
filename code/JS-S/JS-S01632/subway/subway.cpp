// phigros chapter 9
// what do you want more than a happy ending?
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp ' '
#define int long long
int c,n,m,d,q;
int w[500005];
int t[500005][25][2];
int cnt[500005];
int k,tmp,ttm;
vector<int>a[505];
vector<int>at[505];
struct nda{
    int x, t;
    bool operator <(const nda a)const{
        return t>a.t;
    }
};
void solve(){
    while(q--){
        priority_queue<nda>qq;
        int vst[500005];
        memset(vst,0x3f,sizeof vst);
        cin>>tmp>>ttm;
        qq.push({tmp,0});
        vst[tmp]=0;
        while(!qq.empty()){
            nda nw=qq.top();
            qq.pop();
            if(nw.x==ttm){
                // cout<<w[tmp]<<sp<<w[ttm]<<endl;
                cout<<nw.t+w[tmp]+w[ttm]<<endl;
                break;
            }
            if(nw.t>vst[nw.x])continue;
            for(int i=0;i<cnt[nw.x];i++){
                int tt;
                int sbw=t[nw.x][i][0];
                int len=a[sbw].size();
                // cout<<nw.x<<sp<<sbw<<endl;
                for(int j=0;j<len;j++){
                    tt=nw.t+t[nw.x][i][1]+at[sbw][j];
                    int xx=a[sbw][j];
                    // cout<<sp<<xx<<endl;
                    if(nw.x!=xx&&tt<vst[xx]){
                        // cout<<nw.x<<sp<<xx<<sp<<t[nw.x][i][1]<<sp<<at[sbw][j]<<sp<<tt<<endl;
                        vst[xx]=tt;
                        qq.push({xx,tt});
                    }
                }
            }
        }
        // if(qq.empty())cout<<-1<<endl;
    }
}
void solveb(){
    int T=t[1][0][1];
    
}
void solvec(){}
signed main(){
    #ifndef LOCAL
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            // cout<<k<<sp<<j<<endl;
            cin>>tmp>>ttm;
            a[i].push_back(tmp);
            at[i].push_back(ttm);
            t[tmp][cnt[tmp]][0]=i;
            t[tmp][cnt[tmp]][1]=ttm;
            cnt[tmp]++;
        }
    }
    if(c>=7&&c<=11)solve();
    else if(c>=12&&c<=19)solve();
    else if(c==22||c==23)solve();
    else solve();
    return 0;
}