#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    b[1]=0;
    int ans=1,p=0,l=1,r=1;
    while(r<n){
        int k=(r-l+1)*b[r+1];
        if(k+p<=m)p+=k,r++;
        else p-=a[r]-a[l],l++;
        r=max(r,l);
        ans=max(ans,r-l+1);
        //cout<<ans<<" "<<l<<" "<<r<<" "<<p<<endl;
    }
    cout<<ans;
    return 0;
}
