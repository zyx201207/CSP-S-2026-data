#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;long long m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int i=1,j=0/*[]*/,ans=0;long long use=0;
    while(true){
        while(use<=m){
            use+=(j-i+1)*(a[j+1]-a[j]);
            j++;if(j>n)break;
        }ans=max(ans,j-i/*[)*/);
        if(j>n)break;
        while(use>m){
            use-=a[j]-a[i];
            i++;
        }
    }cout<<ans;
    return 0;
}
