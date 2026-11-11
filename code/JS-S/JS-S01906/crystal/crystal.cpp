#include<cstdio>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    int ans2=1;


    for(int i=0;i<n-1;i++){
        int j=i+1;
        int ans=0;
        int tmp=0;
        while(tmp<=m&&j<=n){

            tmp+=(j-i)*(a[j]-a[j-1]);
            ans++;
            j++;
        }
        ans2=max(ans,ans2);
    }
    cout<<ans2;
    return 0;
}
