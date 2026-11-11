#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[600000]={},s=0,ma,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=a[2];i<=a[n];i++){
        s=0;
        ans=0;
        for(int j=1;j<=n;j++){
            if(a[j]<a[i] and s+a[i]-a[j]<=m){
                s+=a[i]-a[j];
                ans++;
            }
            else if(a[j]==a[i]){
                ans++;
            }
        }
        ma=max(ma,ans);
    }
    cout<<ma;
    return 0;
}
