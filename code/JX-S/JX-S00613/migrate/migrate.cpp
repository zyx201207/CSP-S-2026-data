#include<bits/stdc++.h>
using namespace std;
int a[2000005],d,n,minn,ans,sum;

void bfs(int s,int t,int num){
    if(s>t||num>minn) return;
    if(s==t&&num<minn){
        minn=num;
        sum=1;
        return;
    }
    if(s==t&&num==minn){
        sum++;
        return;
    }
    int pos=upper_bound(a+1,a+1+n,a[s]+d)-a-1;
    for(int i=pos;i>s;i--){
        bfs(i,t,num+1);
    }

}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(1){
                    minn=0x3f3f3f3f3f3f3f3f;
                    sum=0;
                    bfs(i,j,0);
                    if(sum==2){
                        //cout<<i<<' '<<j<<'\n';
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
