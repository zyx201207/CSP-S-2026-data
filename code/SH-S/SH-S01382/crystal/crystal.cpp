#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans,k;
long long m,a[N],u;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ans=0,u=m;
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=u){
                ans++;
                u-=(a[i]-a[j]);
            }
            if(a[i]-a[j]>u) break;
        }
        k=max(k,ans);
    }
    cout<<k+1;
}
