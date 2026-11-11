#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100000010],ans,p;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long c=n;
    long long x=m;
    for(int i=0;i<n;i++){
        x=m;
        for(int j=i;j<n;j++){
            if(a[j]-a[i]<=x){
                ans++;
                x=x-a[j]+a[i];
            }
            if(a[i]<a[j] && x>=a[j]-a[i] && a[i]<0 && a[j]<0) ans++;
        }
        p=max(p,ans);
        ans=0;
    }
    cout<<p;
    return 0;
}
