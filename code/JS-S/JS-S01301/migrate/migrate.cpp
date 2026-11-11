#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,m,c,t,d,a[N],to,nans,tomax[N],dqq=0,f=1;
int ans;
void dfs(long long x,long long nbs,long long mbbs){
    if(x==to){
        if(nbs==mbbs){
            nans++;
        }
    }
    if(nans>2||nbs>=mbbs){
        return;
    }
    for(int i=x+1;i<=tomax[x];i++){
        dfs(i,nbs+1,mbbs);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i1=1;i1<=t;i1++){
        cin>>n>>d;
        f=1;
        dqq=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=2){
                dqq=a[i]-a[i-1];
                if(dqq!=a[2]-a[1]){
                    f=0;
                }
            }
        }
        if(c==11||c==12){
            ans=d/dqq;
            if(ans==1){
                cout<<0<<'\n';
                continue;
            }
            ans+=ans-1;
            ans=n-ans;
            ans=max(ans,0);
            cout<<ans<<'\n';
            continue;
        }
        else if(c==13||c==14){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    tomax[i]=j;
                }
            }
        }
        tomax[n]=n;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                nans=0;
                int dis=0;
                int last=i;
                for(int k=i;k<=j;k++){
                    k=tomax[k];
                    dis++;
                }
                //cout<<"i,j,dis"<<i<<j<<dis<<'\n';
                to=j;
                dfs(i,0,dis);
                if(nans==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
