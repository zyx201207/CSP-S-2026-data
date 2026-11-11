#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        int L=0,R=i;
        while(L+1<R){
            int mid=L+R>>1;
            int len=i-mid;
            if(a[i]*len-(s[i-1]-s[mid-1])<=m){
                R=mid;
            }else{
                L=mid;
            }
        }
        ans=max(i-R+1,ans);
    }
    cout<<ans;

    return 0;
}

//len=i-mid
//a[i]*len-(sum[i-1]-sum[mid-1])<=m
