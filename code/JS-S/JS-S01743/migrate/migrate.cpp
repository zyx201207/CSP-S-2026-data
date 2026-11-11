#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int c,t,n,d;
int x[N+10];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0,y=0;
        bool f=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                int s=i,s1,dis=0;
                bool f=1;
                s1=s;
                while(x[s]<x[j]){
                    s1=s;
                    s=upper_bound(x+1,x+n+1,x[s]+d)-x-1;
                    if(s==s1){
                        f=0;
                        break;
                    }
                    dis++;
                }
                if(!f) continue;
                dis--;
                int sum=0;
                for(int k=0;k<=(1<<(j-i-1))-1;k++){
                    if(sum>2) break;
                    int num=0;
                    for(int l=0;l<j-i-1;l++) if((k&(1<<l))==(1<<l)) num++;
                    if(num!=dis) continue;
                    int r=i;
                    for(int l=0;l<j-i-1;l++){
                        if((k&(1<<l))==(1<<l)){
                            if(x[l+i+1]-x[r]>d) break;
                            r=l+i+1;
                        }
                    }
                    if(x[j]-x[r]<=d) sum++;
                }
                if(sum==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}