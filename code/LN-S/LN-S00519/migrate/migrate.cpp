#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,tto[N],need[N],c[N];
long long d,a[N];
int bit[N];
inline int lowbit(int x){return x&(-x);}
inline void clear(){
    for(int i=0;i<=5005;i++)
        bit[i]=0;
}
inline void add(int id,int v){
    while(id<=5005) 
        bit[id]+=v,id+=lowbit(id);
    return ;
}
inline int qua(int id){
    int ans=0;
    while(id)
        ans+=bit[id],id^=lowbit(id);
    return ans;
}
vector<pair<int,int>> aa;
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    tto[0]=1;
    for(int i=1;i<=n;i++){
        int j=tto[i-1];
        while(j<n&&a[j+1]<=a[i]+d) j++;
        tto[i]=j;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int now=i; clear(); add(i,1); add(i+1,-1);
        aa.clear(); aa.push_back({i,i});
        while(now!=n){
            for(int j=now+1;j<=tto[now];j++)
                need[j]=need[now]+1;
            aa.push_back({now+1,tto[now]});
            now=tto[now];
        }
        c[i]=1;
        for(int id=0;id+1<aa.size();id++){
            auto p=aa[id];
            int l=p.first,r=p.second;
            for(int j=l;j<=r;j++){
                int ll=r+1,rr=tto[j];
                if(ll>rr) continue;
                add(ll,qua(j)); add(rr+1,-qua(j));
            }
        }
        for(int j=i+1;j<=n;j++)
            ans+=qua(j)==2;
    }
    cout<<ans<<'\n';
    return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int qgd,T;cin>>qgd>>T;
    while(T--) solve();
    return 0;
}
