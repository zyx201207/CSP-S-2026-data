#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n,lst,fa[N],s[N],sum[N],ans[N],nxt[N],pre[N];
ll re,d,a[N];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void Union(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        re=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            fa[i]=i;
            s[i]=sum[i]=ans[i]=0;
        }
        int p=1;
        for(int i=1;i<=n;i++){
            while(p<n&&a[p+1]-a[i]<=d) p++;
            nxt[i]=p;
        }
        p=n;
        for(int i=n;i>=1;i--){
            while(p>1&&a[i]-a[p-1]<=d) p--;
            pre[i]=p;
        }
        for(int i=2;i<n;i++){
            if(pre[nxt[i]]==i) Union(i,nxt[i]);
        }
        int l=0,r=1;
        for(int i=1;i<=n;i++){
            s[find(pre[i])]++;
            ans[pre[i]]++;
        }
        //for(int i=1;i<=n;i++) cout<<nxt[i]<<' ';
        //cout<<'\n';
        //for(int i=1;i<=n;i++) cout<<pre[i]<<' ';
        //cout<<'\n';
        for(int i=1;i<=n;i++){
            while(l<n&&nxt[l+1]<=i){
                l++;
                sum[find(nxt[l])]++;
            }
            int x=nxt[nxt[i]];
            while(r<=n&&pre[r]<x){
                s[find(pre[r])]--;
                r++;
            }
            int cnt=(pre[nxt[nxt[i]]]==nxt[i]-1);
            if(pre[pre[x]]==i&&nxt[i]==pre[x]+1&&x-i>=2){
                //cout<<i<<' '<<x<<'\n';
                re+=1ll*(sum[find(i)]+1)*(s[find(x)]+1);
                //cout<<i<<' '<<x<<'\n';
            }
            if(nxt[i]-i>=2&&pre[nxt[i]-1]<i){
                re+=ans[nxt[i]-1]-cnt;
                //cout<<"a "<<i<<' '<<cnt<<'\n';
                //cout<<i<<' '<<nxt[i]<<' '<<ans[nxt[i]-1]<<'\n';
            }
            if(nxt[i]-i>=2&&pre[nxt[i]-1]==i){
                re+=1ll*(sum[find(i)]+1)*(ans[nxt[i]-1]-cnt);
                //cout<<"b "<<i<<' '<<cnt<<'\n';
                //cout<<i<<' '<<nxt[i]<<' '<<ans[nxt[i]-1]<<'\n';
            }
        }
        for(int i=1;i<=n;i++) ans[i]=s[i]=0;
        for(int i=1;i<=n;i++) ans[nxt[i]]++;
        p=n;
        for(int i=n;i>=1;i--){
            while(p>=1&&pre[p]>=i){
                s[find(pre[p])]++;
                p--;
            }
            int cnt=(nxt[pre[pre[i]]]==pre[i]+1),x=pre[pre[i]];
            if(i-pre[i]>=2&&nxt[pre[i]+1]==i){
                //cout<<"c "<<i<<' '<<cnt<<'\n';
                re+=1ll*(s[find(i)]+1)*(ans[pre[i]+1]-cnt);
            }
        }
        cout<<re<<'\n';
    }
    return 0;
}
