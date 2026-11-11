#include<bits/stdc++.h>
using namespace std;
long long n,m,last=1,ans=1;
long long a[500001],b[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=2;i<=n;i++)
        for(int j=last;j<=i;j++){
            if(i==j){
                last=j;
                break;
            }
            long long t=(i-j)*a[i];
            if(t-b[i-1]+b[j-1]<=m){
                long long k=i-j+1;
                ans=max(ans,k);
                last=j;
                break;
            }
        }
    cout<<ans;
    return 0;
}
