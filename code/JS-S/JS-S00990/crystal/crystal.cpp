#include <bits/stdc++.h>
using namespace std;
long long m,ans=1;
int n;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        long long sum=0;
        long long cnt=0;
        for(int j=i;j>=1;j--){
            sum+=(a[i]-a[j]);
            if(sum>m) {break;}
            else cnt++;
        }
        ans=max(ans,cnt);
        if(cnt<ans) break;
    }
    cout<<ans;
    return 0;
}
