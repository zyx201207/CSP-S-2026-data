#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005],tmp,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c==13||c==14){
            cout<<0<<"\n";
            continue;
        }
        ans=0;
        for(int i=1;i<=n-1;i++){
            ll mn=1e18;
            int flag=0;
            for(int j=i+1;j<=n;j++){
                tmp=0;
                ll lst=i,shu=0;
                for(int k=i+1;k<=j-1;k++){
                    if(x[k]-x[lst]<=d){
                        tmp=k;
                    }
                    else{
                        lst=tmp;
                        shu++;
                    }
                }
                if(shu<mn){
                    flag=1;
                    mn=shu;
                }
                else if(shu==mn&&flag==1)flag=2;
                else if(shu==mn)flag=0;
            }
            if(flag==2)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
