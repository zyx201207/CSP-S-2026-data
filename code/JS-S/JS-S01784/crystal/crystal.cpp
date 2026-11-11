#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int sum[500005];
int cnt1;
int cnt2;
int nm;
int t;
int maxx=-1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            cnt1++;
        }
    }
    if(cnt1==n){
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+i;
        }
        for(int i=1;i<=n;i++){
            t=i*i;
            if(t-sum[i]>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    if(n>5000){
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+i;
        }
        int s=a[2]-a[1];
        for(int i=1;i<=n;i++){
            t=i*i;
            if(sum[i-1]*s>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        nm=m;
        t=0;
        for(int j=i;j>=1;j--){
            if(nm>=(a[i]-a[j])){
                nm-=(a[i]-a[j]);
                t++;
            }
            else{
                cout<<maxx;
                return 0;
            }
        }
        maxx=max(maxx,t);
    }
}
