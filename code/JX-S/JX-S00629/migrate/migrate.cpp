#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ans;
long long dfs(long long l,long long r,long long cnt,long long num,long long gol){
    if(cnt==r&&num==gol)return 1;
    else if(cnt==r||num==gol)return 0;
    int sum=0;
    for(long long i=cnt+1;i<=n-(gol-cnt)+1;i++){
        if(a[i]-a[cnt]>d)break;
        sum+=dfs(l,r,i,num+1,gol);
    }
    return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        for(int k=4;k<=n;k++){//qujian
            for(int l=1;l<=n-k+1;l++){//[l,r]
                long long r=l+k-1;
                for(int q=2;q<n;q++){//len
                    long long num=dfs(l,r,l,1,q);
                    if(num>0&&num!=2)break;
                    if(num==2){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
