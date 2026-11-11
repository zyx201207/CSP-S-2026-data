#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum[n],mm=0;
    for(int i=0;i<n;i++){
        sum[i]=0;
    }
    for(int i=0;i<n;i++){
        mm=0;
        for(int j=0;j<n;j++){
            if(a[i]<=a[j]){
                mm+=(a[j]-a[i]);
                sum[i]++;
            }
        }
        if(mm>m) sum[i]=0;
    }
    int maxn=-1;
    for(int i=0;i<n-1;i++){
        maxn=max(maxn,max(sum[i],sum[i+1]));
    }
    cout<<maxn;
    return 0;
}
