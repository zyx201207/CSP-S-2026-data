#include<bits/stdc++.h>
using namespace std;
long long a[500050],s[500050],n,m,ans=0,l,r,mm;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=0;i<n;i++){
        l=0,r=i-1;
        while(l<=r){
            long long mid=(l+r)>>1;
            if(a[i]*mid<=m+s[i-1]-s[i-mid-1]){
                mm=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ans=max(ans,mm);
    }
    cout<<ans+1<<endl;
    return 0;
}
//100 pts ?
//I'm exhausted
//ccf v me 50
