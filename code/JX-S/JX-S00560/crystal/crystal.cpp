#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n,m;
int pos,ans=0,loc;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int T=m;
        int cnt=1;
        for(int j=i-1;j>=1&&T-a[i]+a[j]>=0;j--){
            cnt++;
            T=T-a[i]+a[j];
        }
        if(cnt>ans)
            ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
