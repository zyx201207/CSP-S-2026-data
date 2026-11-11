#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,d,a[N],cnt,num,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]-a[i-1]>d) num=i;
        }
        ans=0;
        for(int len=d+1;len<=num;len++){
            cnt=0;
            for(int i=1;i<=num-len+1;i++){
                for(int j=i+1;j<=i+len-1;j++){
                    if(a[j]-a[i]<=d&&a[i+len-1]-a[j]<=d) cnt++;
                }
            }
            if(cnt%2==0) ans+=(cnt/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
