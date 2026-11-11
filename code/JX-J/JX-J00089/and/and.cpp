#include<bits/stdc++.h>
using namespace std;
long long a[200001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        long long ans=a[1];
        for(long long i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        long long ans=a[1];
        for(long long i=2;i<=n;i++){
            ans=max(a[i],ans);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        long long ans=0;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    else{
        sort(a+1,a+1+n,cmp);
        long long ans=a[1];
        for(long long i=2;i<=m;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
}
