#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long x=m;
    for(long long i=2;i<=n;i++){
        for(long long j=1;j<i;j++){
            if(a[j]<a[i]){
                long long y=a[j];
                a[j]=a[i];
                if(x-(a[j]-y)>=0){
                    x-=a[j]-y;
                }
                else a[j]=y;
            }
        }

    }
    for(long long i=1;i<=n;i++){
        b[a[i]]++;
    }
    for(int i=1;i<=500005;i++){
        ans=max(ans,b[i]);
    }
    cout<<ans;
    return 0;
}
