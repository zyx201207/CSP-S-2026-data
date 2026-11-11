#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int MAXN=5e5+5;
long long a[MAXN],s[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<n;i++){
        int l=i,r=n;
        while(l<=r){
            long long mid=(l+r)>>1;
            long long yq=a[mid]*(mid-i+1);
            long long zg=yq-s[mid]+s[i-1];
            if(zg<=m){
                l=mid+1;
                ans=max(ans,mid-i+1);
            }else{
                r=mid-1;
            }
        }
        if(ans==n){
            break;
        }
    }
    cout<<ans;
    return 0;
}
