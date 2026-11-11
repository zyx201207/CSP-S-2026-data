#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long maxn=-1;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    else if(m==n){
        long long cnt=a[1];
        for(int i=2;i<=n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
        return 0;
    }
    else if(m==2){
        long long maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long x=a[i]&a[j];
                maxn=max(maxn,x);
            }
        }
        cout<<maxn;
        return 0;
    }
    else if(m=n-1){
         long long maxn=-1;
        for(int i=1;i<=n;i++){
                long long cnt=a[1];
            for(int j=2;j<=n;j++){
                cnt&=a[j];
            }
            maxn=max(cnt,maxn);
        }
        return 0;
    }
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
    }
    cout<<maxn;
    return 0;
}
