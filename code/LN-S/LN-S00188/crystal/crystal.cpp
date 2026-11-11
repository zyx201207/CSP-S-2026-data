#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;
long long a[500005],b[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        c[i]=c[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        long long num=0;
        for(int j=i;j<=n;j++){
            num+=c[i];
            if(num>m){
                if(ans<j-i+1){
                    ans=j-i;
                }
            }
        }
    }cout<<ans;
    return 0;
}
