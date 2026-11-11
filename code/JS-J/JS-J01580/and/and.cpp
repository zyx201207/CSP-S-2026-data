#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,m,ans,maxans;
LL a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    ans=a[1],maxans=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        ans=a[i]&ans;
        maxans=max(a[i],maxans);
    }
    if(m==1) cout<<maxans;
    else if(m==n) cout<<ans;
    else{
            maxans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++) maxans=max(maxans,a[i]&a[j]);
        }
        cout<<maxans;
    }
    return 0;
}
