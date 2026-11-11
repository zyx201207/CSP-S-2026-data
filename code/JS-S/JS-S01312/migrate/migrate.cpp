#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,x[2000005],cnt;
int _find(long long a,long long b){
    if(b==x[1]) cnt++;
    for(int i=1;i<=a;i++){
        int flag=0;
        for(int j=1;j<=n;j++){
            if(x[j]==b-i) flag=1;
        }
        if(flag) return _find(a,b-i);
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        cin>>n>>d;
        for(long long j=1;j<=n;j++){
            cin>>x[j];
            if(_find(d,x[n])==2) ans++;
            cnt=0;
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
