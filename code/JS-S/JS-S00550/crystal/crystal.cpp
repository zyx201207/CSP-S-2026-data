#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flg=1;
    long long k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    k=a[2]-a[1];
    for(int i=2;i<n;i++){
        if(a[i+1]-a[i]!=k){
             flg=0;
             break;
        }
    }
    if(flg==1&&k==1){
        int maxn=-1;
        for(int i=1;i<=n;i++){
            long long sum=0;
            sum=(i-1)*i/2;
            if(sum<=m){
                maxn=i;
            }
        }
        cout<<maxn;
        return 0;
    }
    if(flg==1){
        int maxn=-1;
        for(int i=1;i<=n;i++){
            long long sum=0;
            sum=(i-1)*i/2*k;
            if(sum<=m){
                maxn=i;
            }
        }
        cout<<maxn;
        return 0;
    }
    int maxn=-1;
    for(int i=1;i<=n;i++){
        long long sum=0;
        int ans=0;
        for(int j=i;j>=1;j--){
            sum+=abs(a[i]-a[j]);
            if(sum<=m){
                ans++;
            }
            maxn=max(maxn,ans);
        }
    }
    cout<<maxn;
    return 0;
}

