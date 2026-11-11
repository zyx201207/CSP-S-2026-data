#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,r[N];
ll x[N],curmin,ans,cnt;
void dfs(int x,int s,int t,unsigned ll cur){
    if(x==t){
        cout<<s<<" "<<t<<" "<<cur<<"\n";
        if(cur==curmin){
           cnt++;
        }
        else if(cur<curmin){
            curmin=cur;
            cnt=0;
        }
        return;
    }
    for(int i=x+1;i<=r[i];i++){
        dfs(i,s,t,cur+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            r[i]=min(1LL*n,lower_bound(x+i,x+n+1,x[i]+d)-x);
            for(int j=1;j<i;j++){
                cout<<"\n";
                ans=0;
                dfs(j,j,i,0);
                if(cnt==2){
                    ans++;
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
