#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005],diff[5005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mid=n/2+2;
    for(int i=1;i<=n/2+1;i++){
        diff[i]=abs(a[mid]-a[i]);
    }
    sort(diff+1,diff+n+1);
    for(int i=1;i<=n;i++){
        m-=diff[i];
        if(m<=0) break;
        ans++;
    }
    cout<<ans;
    return 0;
}