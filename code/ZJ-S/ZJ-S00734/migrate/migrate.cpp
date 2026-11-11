#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T,n; ll d;
ll x[2000010];
int r[2000010],op[2000010];
ll f[2000010];
ll g[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>c>>T;
    for(int _=1;_<=T;_++){
        cin>>n>>d;
        for(int i=1;i<=n;i++) f[i]=1,g[i]=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1,j=1;i<=n;i++){
            while(j<n&&x[j+1]-x[i]<=d) ++j;
            r[i]=j;
        }
        for(int i=1;i<=n;i++){
            if(i==1||r[i]>r[i-1]) op[i]=0;
            else if(r[i]==r[i-1]&&r[i-1]>r[i-2]) op[i]=1;
            else if(r[i]==r[i-1]&&r[i-1]==r[i-2]) op[i]=2;
        }
        for(int i=1;i<=n;i++){
            if(r[i]!=i){
                if(op[i]==0) f[r[i]]+=f[i];
                else f[r[i]]++;
            }
        }
        for(int i=n;i>=1;i--){
            g[i]=r[i]-max(i,r[i-1]);
            if(op[i]==0&&r[i]>i) g[i]+=g[r[i]];
        }
        ll ans=0;
        for(int i=1;i<n;i++){
            int j=r[i];
            if(i+2>j) continue;
            if(op[j]==2) continue;
            int sz=f[i];
            if(op[i]!=0||r[i-1]>=j-1) sz=1;
            ans+=1LL*(max(0,r[j-1]-max(j,r[j-2])))*sz;
            if(op[j]==1&&r[j]>j) ans+=1LL*sz*g[r[j]];
        }
        cout<<ans<<'\n';
    }
    return 0;
}