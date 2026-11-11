//100pts 14:39
#include<bits/stdc++.h>
#define ll long long
const int N=5e5+5;
using namespace std;
ll n,m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for (int i=1;i<=n;i++){
        int l=1,r=i,mid,res=i;
        while (l<=r){
            mid=(l+r)/2;
            if (s[i]-s[mid-1]+m>=a[i]*(i-mid+1)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
}
/*
5 500000000000
100000000000 200000000000 400000000000 800000000000 900000000000
*/
