#include<bits/stdc++.h>
using namespace std;
int n,cf,ans=0;
long long m,ave=0,cen=INT_MAX;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ave+=a[i];
    }
    sort(a+1,a+n+1);
    ave/=n;
    for(int i=1;i<=n;i++){
        if(abs(a[i]-ave)<=abs(cen-ave)){
            cen=a[i];
            cf=i;
        }
    }
    for(int i=1;i<=cf;i++){
        if(abs(cen-a[i])<=m){
            m-=(abs(cen-a[i]));
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
