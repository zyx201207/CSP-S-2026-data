#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],c[500010],m,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        c[i]=a[i+1]-a[i];
    }
    for(long long i=1;i<=n;i++){
        long long he=0;
        for(long long j=1;j<i;j++){
            bool bo=true;
            for(long long k=j;k<i;k++){
                he+=(k-j+1)*c[k];
                if(he>m)break;
                if(k==i-1&&he<=m){
                    ans=max(ans,i-j+1);
                    bo=false;
                }
            }
            if(bo==false)break;
        }
    }
    cout<<ans;
    return 0;
}
