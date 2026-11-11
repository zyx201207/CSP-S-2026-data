#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long a[501000],s[500100],m,b[500100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
        b[i]=b[i-1]+s[i];
    }
    int l=1,r=2;
    long long x=s[2];
    while(r<=n){
        if(x<=m){
            ans=max(ans,r-l+1);
            r++;
            x=x+(r-l)*s[r];
        }
        else{
            l++;
            x=x-(b[r]-b[l-1]);
        }
    }
    cout<<ans;
    return 0;
}
