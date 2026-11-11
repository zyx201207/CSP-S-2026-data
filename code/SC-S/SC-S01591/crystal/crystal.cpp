#include<bits/stdc++.h>
using namespace std;
long long n,a[1000006],m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int j=1;
    for(int i=1;i<=n;i++){
        m-=(i-j)*(a[i]-a[i-1]);
        while(m<0){
            m+=(a[i]-a[j]);
            j++;
        }
        ans=max(i-j+1ll,ans);
    }
    cout<<ans;
    return 0;
}