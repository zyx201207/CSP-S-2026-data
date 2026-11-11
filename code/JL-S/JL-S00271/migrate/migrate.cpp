#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
int n,c,t,d,x[2000005],A=1;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        A=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2]) A=0;
        }
        if(n<=3){
            cout<<"0\n";
            continue;
        }
        if(A){
            if(d<2*(x[2]-x[1])) cout<<"0\n";
            else{
                int qsy=d/(x[2]-x[1]),rlz=n-(qsy*2-1);
                if(n<qsy*2){
                    cout<<"0\n";
                    continue;
                }
                cout<<rlz<<'\n';
            }
        }
        else{
            int ans=0,cnt=0;
            for(int i=1;i<n-2;i++){
                for(int j=i+3;j<=n;j++){
                    if(x[j]-x[i]<=d) continue;
                    if(x[j]-x[i]>=2*d) break;
                    for(int k=i+1;k<j;k++){
                        if(x[k]-x[i]<=d&&x[j]-x[k]<=d) cnt++;
                    }
                    if(cnt==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
