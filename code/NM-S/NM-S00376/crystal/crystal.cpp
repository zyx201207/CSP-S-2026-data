#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,load;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m,a[0]=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        long long run=i-1,more=m,load=0;
        while(more>=a[i]-a[run]){
            more=more-(a[i]-a[run]);
            load++;
            run--;
        }
        ans=max(ans,load);
    }
    cout<<ans+1;
    return 0;
}
