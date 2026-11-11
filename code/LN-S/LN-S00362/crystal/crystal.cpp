#include<bits/stdc++.h>
using  namespace std;
int n,m,a[500020],ans,ans1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
        int m1=m;
        ans1=1;
    for(int j=i-1;j>=1;j--){
        if(m1>=a[i]-a[j]){
            ans1++;
            m1-=(a[i]-a[j]);
        }else{
            break;
        }
    }
    ans=max(ans,ans1);
}
cout<<ans;
}
