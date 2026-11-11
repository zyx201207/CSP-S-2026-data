#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e6+5;
int c,T,n,pre1,pre2;
ll d,x[N],sum,presum,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c==11||c==12){
            if(d<=x[2]-x[1]){
                cout<<"0\n";
                continue;
            }
            cout<<max(0LL,(ll)n-2*d/(x[2]-x[1])+1)<<'\n';
        }else{
            ans=0;
            for(int i=1;i<n;i++){
                sum=presum=0,pre1=pre2=0;
                for(int j=i+1;j<=n;j++){
                    if(sum-x[j-1]+x[j]>d)pre2=pre1,pre1=j-1,presum=sum,sum=x[j]-x[j-1];
                    else sum+=-x[j-1]+x[j];
                    if(pre1&&sum-x[pre1-1]+x[pre1]<=d&&sum-x[pre1-2]+x[pre1]>d&&(!pre2||presum-x[pre2-1]-x[pre1]+x[pre2]+x[pre1-1]>d))ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
