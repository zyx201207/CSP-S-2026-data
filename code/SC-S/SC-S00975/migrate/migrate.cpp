#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,x[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int sum=0;
                for(int k=i+2;k<=j;k++){
                    if(x[k]-x[k-2]<=d) sum++;
                }
                if(sum==1) ans++;
            }
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}
