#include<bits/stdc++.h>
using namespace std;
long long a[500010],m,ans=0;
int mx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=0,r=1;
    while(r<n){
        r++;
        ans+=(r-l-1)*(a[r]-a[r-1]);
        while(ans>m){
            l++;
            ans-=a[r]-a[l-1];
        }
        mx=max(mx,r-l);
    }
    cout<<mx;
    return 0;
}
