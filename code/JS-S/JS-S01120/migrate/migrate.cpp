#include<bits/stdc++.h>
using namespace std;
int c,t,il[2000006];
long long n,d,l,r,mid,cnt,mindep;
long long x[2000006],ans;
void dfs(int x,int y,int dep){
    if(x==y){
        if(dep=mindep)cnt++;
        if(dep<mindep){
            cnt=1;
            mindep=dep;
        }
    }
    if(x>y)return;
    dfs(il[x],y,dep+1);
    dfs(il[x]-1,y,dep+1);
    dfs(il[x]-2,y,dep+1);
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n;i++){
            l=i,r=n;
            while(l<=r){
                mid=(l+r)/2;
                if(x[mid]-x[i]<=d){
                    cnt=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            il[i]=cnt;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mindep=0;
                cnt=0;
                dfs(i,j,0);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            x[i]=0,il[i]=0;
        }
    }

}
