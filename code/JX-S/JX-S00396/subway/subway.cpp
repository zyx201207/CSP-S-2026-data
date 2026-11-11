#include<bits/stdc++.h>
#define ll long long
#define N 500015
using namespace std;
ll n,m,v,c,b[N],s=1e9+7,d,q,z,f[N],x,visit[N];
struct q{
    ll chang;
    vector<ll>p;
    vector<ll>o;
    map<ll,ll>u;
}a[510];
map<ll, ll>p;
map<ll,map<ll,ll> >o,u;
struct w{
    vector<ll>t;
}h[N];
void dfs1(ll x,ll y,ll c){
    if(x==p[y]){
        s=min(s,c);
        return;
    }
    if(visit[x]==1){
        return ;
    }
    visit[x]=1;
    for(int i=1;i<=n;i++){
        if(o[x][i]==1){
            if(x==i){
                continue;
            }
            dfs1(i,y,c+1);
        }
    }
    visit[x]=0;
    return ;
}
void dfs(ll x,ll y,ll g){
  //  cout<<x<<" "<<y<<" "<<g<<endl;
    if(x==y){

        s=min(s,g);
        return ;
    }
    for(ll i=0;i<h[x].t.size();i++){
        for(ll j=0;j<a[h[x].t[i]].chang;j++){
            ll t=a[h[x].t[i]].o[j];
            ll k=g+a[h[x].t[i]].p[a[h[x].t[i]].u[x]]+a[h[x].t[i]].p[a[h[x].t[i]].u[t]];
            if(f[t]<k){
                continue;
            }
            else{//cout<<1<<endl;
                f[t]=k;
                if(x==t){
                    continue;
                }
                dfs(t,y,k);
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    if((c>=12&&c<=19)||(c==0)){
            ll f=0;
            s=1e9+7;
        for(int i=1;i<=n;i++){
            ++f;
            cin>>a[i].chang;
            for(int j=1;j<=n;j++){
                cin>>z>>x;
                if(p[z]!=0){
                    o[p[z]][f]=1;
                    u[f][p[z]]=1;
                }
                else{
                    p[z]=f;
                }


            }
            d=x;
        }
        while(q--){
            cin>>x>>z;
            s=1e9+7;
            dfs1(p[x],z,0);
            cout<<s*d+b[x]+b[z]<<endl;
        }
        return 0;

    }
    for(int i=1;i<=n;i++){
        cin>>a[i].chang;
        for(int j=0;j<a[i].chang;j++){
            cin>>z>>x;
            a[i].u[z]=j;
            a[i].o.push_back(z);
            h[z].t.push_back(i);
            a[i].p.push_back(x);
        }
    }

   /* for(int i=1;i<=n;i++){
        cout<<a[i].chang<<endl;;
        for(int j=0;j<a[i].chang;j++){
            cout<<a[i].u[a[i].o[j]]<<" "<<a[i].o[j]<<" "<<a[i].p[j]<<endl;
            ;
            ;
            ;
        }
    }
    return 0;*/
    for(int i=1;i<=q;i++){
        memset(f,127,sizeof(f));
        cin>>x>>z;
        dfs(x,z,0);
        cout<<s+b[x]+b[z]<<endl;
    }
    return 0;
}
