#include<bits/stdc++.h>
using namespace std;
using in=long long;
in sum[2000005],a[2000005];
map<pair<in,in>,in>mp;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    in c,t;
    cin>>c>>t;
    while(t>0){
        in n,d;
        cin>>n>>d;
        memset(sum,0,sizeof sum);
        memset(a,0,sizeof a);
        in ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            if(i==1)ans++;
            if(a[i]-a[i-1]==a[2]-a[1])ans++;
        }
        if(ans==n){
            in u=d/(a[2]-a[1]);
            if(u==2&&n>=3){
                cout<<n-3;
            }
            else{
                cout<<0;
            }
            cout<<'\n';
        }
        t--;
    }
    return 0;
}
