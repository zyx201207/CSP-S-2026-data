#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(m==1){cout<<a[n]<<endl;return 0;}
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans<<endl;
        return 0;
    }
    if(m=n-1){
        int x=n;
        int sum=a[1];
        while(x>=2){
            for(int i=2;i<=n;i++)if(i!=x)sum=sum&a[i];
            x--;
            ans=max(ans,sum);
        }
        sum=a[2];
        for(int i=3;i<=n;i++)sum=sum&a[i];
        cout<<max(ans,sum)<<endl;
        return 0;
    }
    ans=a[1];
    for(int i=2;i<=m+1;i++)ans=ans&a[i];
    cout<<ans<<endl;
    return 0;
}
