#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
const ll INF = 1e15;
struct sbw{
    ll a,t,line;
};
vector<sbw> L[510];
vector<sbw> G[N];
int w[N];
int c,n,m,d,q;
int st,ed;
ll ans=INF;
bool vis[N];
void dfs(int u,int fa,ll t,int li){
    //cout<<fa<<" -> "<<u<<"  t:" << t<<endl;
    if(u==ed){
        ll lngg=0;
        for(auto i=0;i<=L[li].size();i++){
            if(L[li][i].a==ed){
                lngg=L[li][i].t;
                break;
            }
        }
        //cout<<"end:"<<lngg<<endl;
        ans=min(ans,t+lngg);
        //cout<<"**t:"<<ans<<endl;
        return ;
    }
    //cout<<"t:"<<t<<endl;
    for(auto nx : G[u]){
        //cout<<"v: "<<nx.a<<endl;
        int v = nx.a;
        if(v==fa) continue;
        //if(vis[v]) continue;
        //vis[v]=1;

        ll lng=0;
        if(nx.line != li){
            if(li!=0){
                for(auto i=0;i<L[li].size();i++){
                    if(L[li][i].a==u){
                       lng+=L[li][i].t;
                       //cout<<"+++\n";
                       break;
                    }
                }
            }

            for(auto i=0;i<L[nx.line].size();i++){
                if(L[nx.line][i].a==u){
                   lng+=L[nx.line][i].t;
                   //cout<<"+++\n";
                   break;
                }
            }
            //if(v==3) cout<<"lng:"<<lng<<endl;
        }
        //if(v==3) cout<<"lng:"<<lng<<endl;
        dfs(v,u,lng+t,nx.line);
    }

}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        int ki;
        cin>>ki;
        for(int j=1;j<=ki;j++){
            ll ak,tk;
            cin>>ak>>tk;
            sbw tmp={ak,tk,i};
            L[i].push_back(tmp);
            //if(L[i][j-1].a == 1) cout<<"++"<<ak<<endl;
            //cout<<"--"<<L[i][j-1].a<<endl;
            if(j>=2){
                G[L[i][j-2].a].push_back(tmp);

            }
        }

    }
    for(int i=1;i<=q;i++){
        //memset(ans,INF,sizeof(ans));
        memset(vis,0,sizeof(vis));
        cin>>st>>ed;
        if(st==ed){
            cout<<0<<endl;
            continue;
        }
        ans=INF;
        //vis[st]=1;
        dfs(st,0,0,0);
        cout<<ans+w[st]+w[ed]<<endl;
    }
    /*
    if(c>=7&&c<=11){
    }else if(c>=12&&c<=19){
    }
    */





    return 0;

}
