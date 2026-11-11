#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5,Mx=1e15+5;
ll c,n,m,d,q,cs[M],mp[N][N];
struct Node{
    ll x,c;
};
vector<Node> s[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>cs[i];
    for(ll i=1;i<=n;i++){
        ll len;
        cin>>len;
        for(ll j=1;j<=len;j++){
            ll to,tc;
            cin>>to>>tc;
            s[to].push_back({i,tc});
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i==j) continue;
            mp[i][j]=Mx;
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll u=0;u<s[i].size();u++){
            for(ll v=u;v<s[i].size();v++){
                if(u==v){
                    mp[s[i][u].x][s[i][v].x]=0;
                    mp[s[i][v].x][s[i][u].x]=0;
                    continue;
                }
                mp[s[i][u].x][s[i][v].x]=min(mp[s[i][u].x][s[i][v].x],s[i][u].c+s[i][v].c);
                mp[s[i][v].x][s[i][u].x]=mp[s[i][u].x][s[i][v].x];
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i==j) continue;
            for(ll k=1;k<=n;k++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]);
            }
        }
    }
    for(ll i=1;i<=q;i++){
        ll bg,ed,ans=0,tans=Mx;
        cin>>bg>>ed;
        ans+=cs[bg]+cs[ed];
        for(ll i=0;i<s[bg].size();i++){
            for(ll j=0;j<s[ed].size();j++){
                ll u=s[bg][i].x,v=s[ed][j].x,c1=s[bg][i].c,c2=s[ed][j].c;
                tans=min(tans,c1+c2+mp[u][v]);
            }
        }
        cout<<ans+tans<<'\n';
    }
	return 0;
}
