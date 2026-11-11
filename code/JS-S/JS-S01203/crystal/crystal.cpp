#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=1;
long long solve(int i){
    long long res=0,t=0;
    long long b[500010];
    memset(b,0,sizeof(b));
    for(long long j=1;j<=n;j++){
        if(i<a[j]){
            break;
        }
        b[++t]=i-a[j];
    }
    long long p=m;
    for(int j=t;p>=0&&j>=1;j--){
        p-=b[j];
        res++;
    }
    return res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=a[1];i<=a[n];i++){
        long long res=solve(i);
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
