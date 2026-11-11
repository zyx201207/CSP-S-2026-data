#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<long long>a(n+5);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    vector<long long>sum(n+5,0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1,l=1;
    for(int r=1;r<=n;r++){
        while(l<=r){
            int cnt=r-l+1;
            int t=a[r-1];
            int cur=sum[r]-sum[l-1];
            int c=cnt*t-cur;
            if(c==m)
                break;
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
