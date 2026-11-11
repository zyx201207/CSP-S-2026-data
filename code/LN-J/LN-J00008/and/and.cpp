#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(long long i=1;i<=n;i++){
            if(a[i]>ans) ans=a[i];
        }
    }
    if(m==2){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                if((a[i]&a[j])>ans) ans=a[i]&a[j];
            }
        }
    }
    cout<<ans;
    return 0;
}
