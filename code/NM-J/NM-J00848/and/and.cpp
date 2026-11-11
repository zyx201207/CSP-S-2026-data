#include<bits/stdc++.h>
using namespace std;
int n,m,s=1,ans=0,p2[40]={1},a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=31;i++)p2[i]=p2[i-1]*2;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+s,a+n+1);
    for(int i=30;i>=0;i--){
        if(a[n]<p2[i])continue;
        for(int j=n;j>=s-1;j--){
            if(j==s-1||a[j]<p2[i]){
                if(n-j>=m){
                    s=j+1;
                    ans+=p2[i];
                    for(int k=s;k<=n;k++)a[k]-=p2[i];
                }
                break;
            }
        }
        sort(a+s,a+n+1);
    }
    cout<<ans;
    return 0;
}
