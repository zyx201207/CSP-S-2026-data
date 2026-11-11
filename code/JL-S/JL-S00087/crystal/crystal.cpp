#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,r=1;
long long m;
long long a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int j=1;j<=n;j++){
        long long lo=1,hi=j,bs=1;
        while(lo<=hi){
            int md=(lo+hi)/2;
            int k=j-md+1;
            long long c=(long long)k*a[j]-(s[j]-s[md-1]);
            if(c<=m){
                bs=k;
                hi=md-1;
            }else{
                lo=md+1;
            }
        }
        if(bs>r){
            r=bs;
        }
    }
    cout<<r;
    return 0;
}
