#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        long long l=i;long long r=n;long long mid=0;
        while(l<=r){
            mid=(l+r)/2;
            if(m>=a[mid]*(mid-i+1)-b[mid]+b[i-1]){
                ans=max(ans,mid-i+1);l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
