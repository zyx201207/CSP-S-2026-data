#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],mi=LLONG_MAX,ma=LLONG_MIN,ans=LLONG_MIN;
int n,m;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int num=0,t=1,sum=0;
    for(int i=1;i<=n;i++){
        sum+=(i-t)*(a[i]-a[i-1]);
        if(sum<=m){
            num++;
            ans=max(ans,num);
            continue;
        }
        while(sum>m){
            num--;
            sum-=a[i]-a[t++];
        }
        num++;
        ans=max(ans,num);
    }
    cout<<ans<<endl;
    return 0;
}
