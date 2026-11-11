#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],tot,lst,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i!=1)tot+=(a[i]-a[i-1])*(i-lst-1);
        while(tot>m){
            lst++;
            tot-=a[i]-a[lst];
        }
        ans=max(ans,i-lst);
    }
    cout<<ans;
    return 0;
}
