#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,a[N];
char c[N];
vector<pair<ll,ll> >g[26];
vector<ll> pre[26];
int lb(const vector<pair<ll,ll> > &v, ll x){
    int m=v.size();
    int L=0,R=m;
    while(L<R){
        int mid=L+R>>1;
        if(v[mid].first>=x)R=mid;
        else L=mid+1;
    }
    return R;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    ll sum=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    ll mid=sum/2;
    ll s=0;
    for(int i=1;i<=n;i++){
        ll L=s+1,R=s+a[i];
        //cout<<L<<" "<<R<<" "<<mid<<"\n";
        if(sum%2==0){
            if(R<=mid){
                g[c[i]-'a'].push_back({L,R});
            }else if(L<=mid&&R>mid){
                g[c[i]-'a'].push_back({L,mid});
                g[c[i]-'a'].push_back({mid+1,R});
            }else{
                g[c[i]-'a'].push_back({L,R});
            }
        }else{
            if(R<=mid){
                g[c[i]-'a'].push_back({L,R});
            }else if(L<=mid&&R==mid+1){
                g[c[i]-'a'].push_back({L,R-1});
            }else if(L<=mid&&R>mid+1){
                g[c[i]-'a'].push_back({L,mid});
                g[c[i]-'a'].push_back({mid+2,R});
            }else{
                g[c[i]-'a'].push_back({L,R});
            }
        }
        s+=a[i];
    }
    ll ans=0;
    for(int u=0;u<26;u++){
        int m=g[u].size();
        // cout<<u<<" "<<m<<"\n";
        // for(int i=0;i<m;i++){
        //      cout<<g[u][i].first<<" "<<g[u][i].second<<"\n";
        // }
        if(!m)continue;
        pre[u].resize(m);
        pre[u][0]=g[u][0].second-g[u][0].first+1;
        for(int i=1;i<m;i++)pre[u][i]=pre[u][i-1]+g[u][i].second-g[u][i].first+1;
        for(int i=0;i<m;i++){
            if(g[u][i].first>mid)break; // only left 
            ll L=sum-g[u][i].second+1,R=sum-g[u][i].first+1;
            // 1. left, jie duan
            int p=lb(g[u],L);
            if(p==m||(p>0&&g[u][p].first>L)){
                int v=p-1;
                if(g[u][v].second<=R)ans+=max(0ll,g[u][v].second-L+1);
                else{
                    ans+=R-L+1; // chuan yue
                    continue;
                }
            }
            // 2. right, jie duan
            int q=lb(g[u],R+1);
            if(q>0){
                int v=q-1;
                if(g[u][v].second>R){
                    ans+=R-g[u][v].first+1;
                }
            }
            // 3. all in 
            if(p==m)continue;
            if(g[u][p].second>R)continue;
            while(q==m||g[u][q].second>R)q--;
            ans+=pre[u][q]-(p>0?pre[u][p-1]:0);
        }
    }
    cout<<sum/2-ans;
    
    return 0;
}