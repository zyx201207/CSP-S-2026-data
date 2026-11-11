#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],x,f,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    x=a[2]-a[1];
    for(int i=2;i<=n;i++)
        if(a[i+1]-a[i]!=x) f=1;
    if(f==0){
        cout<<ceil(m/x);
        return 0;
    }
    for(int i=2;i<=n;i++){
        int s=1,t=0;
        for(int j=i-1;j>=1;j--){
            t+=a[i]-a[j];
            if(t<=m) s++;
            else break;
        }
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}
