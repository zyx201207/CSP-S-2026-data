#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll len=1e6+10;
ll n,c,T,k,ans;
int nw[15];
int dis[15][15];
int cnt[10];
bool vis[15];
vector<int>grap[len];
void dep(int nw,int lst,int rt){
    dis[rt][nw]=dis[rt][lst]+1;
    for(int i=0;i<grap[nw].size();i++){
        if(grap[nw][i]==lst)continue;
        dep(grap[nw][i],nw,rt);
    }
    return ;
}
int cdfs(int x,int lst,int tar){
    int tmp=1;
    for(int i=0;i<grap[x].size();i++){
        int to=grap[x][i];
        if(to==lst)continue;
        if(nw[to]==tar){
            tmp+=cdfs(to,x,tar);
        }
    }
    return tmp;
}
bool check(){
    bool flg1=0,flg2=0;
    for(int i=1;i<=n;i++){
        if(!flg1&&nw[i]==1){
            int tmp=cdfs(i,0,1);
            if(tmp!=cnt[1]){
                return false;
            }
            flg1=1;
        }
        if(!flg2&&nw[i]==2){
            int tmp=cdfs(i,0,2);
            if(tmp!=cnt[2])return false;
            flg2=1;
        }
    }
    return true;
}
void dfs(ll x){
    if(x==n+1){
        if(cnt[1]+cnt[2]!=k)return ;
        if(!check())return ;
        for(int i=1;i<=n;i++){
                if(nw[i]==1||nw[i]==2)vis[i]=1;
                else vis[i]=0;
        }
        ll res=0,tmp=n;
        for(int i=1;i<=n;i++){
            tmp=n;
            if(nw[i]==3){
                for(int j=1;j<=n;j++){
                    if(nw[j]!=3)tmp=min(res,1ll*dis[i][j]);
                }
                res=max(res,tmp);
            }
        }
        ans=min(ans,res);
        return ;
    }
    for(int i=1;i<=3;i++){
        nw[x]=i;
        cnt[i]++;
        dfs(x+1);
        cnt[i]--;
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)grap[i].clear();
        for(int i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            grap[x].push_back(y);
            grap[y].push_back(x);
        }
        if(c<=3){
            ans=n;
            for(int i=1;i<=n;i++){
                dis[i][0]=-1;
                dep(i,0,i);
            }
            dfs(0);
            cout<<ans<<'\n';
        }
        if(c==13||c==14){
            ll l=n/2+2;
            if(k>=l){
                cout<<1<<'\n';
            }
            else{
                if((l-k)%4==0){
                    cout<<(l-k)/4+1<<'\n';
                }
                else if((l-k)%4==1)
                    cout<<ll(ceil((l-k)*1.0/4))<<'\n';
                else cout<<ll(ceil((l-k)*1.0/4))+1<<'\n';
            }
        }
    }
    return 0;
}
/*
100+100+0+15
i'm sorry for T3 since wasting so many time here on T4
i think 1= won't be over 200(?
if it really 200+ there is only myself to blame...

"Daisy, Daisy, give me your answers do"
"I'm half crazy, all for the love of you"
"It won't be a stylish marriage"
"I can't afford a carriage"
"But you look sweet upon the seat of a bicycle built for two"
*/
