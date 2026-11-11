#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m;
int ans;
long long a[N];
long long b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1,j=1;i<=n;i++){
        while((b[i]-b[j-1]+m)<a[i]*(i-j+1))j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}
