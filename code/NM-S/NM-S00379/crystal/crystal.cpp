#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans[500005],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long t=0,v=m;
    for(int i=1;i<n;i++){
        long long  c=(a[t+1]-a[t])*(t-i+1);
        v+=(a[t]-a[i-1]);
        while(v-c>=0&&t<n){
            v-=c;
            t++;
            c=(a[t+1]-a[t])*(t-i+1);
        }
        ans[i]=t;
    }
    long long maxx=-1;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,ans[i]-i+1);
    }
    cout<<maxx;
    return 0;
}
