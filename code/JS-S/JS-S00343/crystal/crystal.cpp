#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],fr[500005],ans,l,r,md;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    sort(a,a+n);
    for(int j=0;j<n;j++){
        fr[j+1]=fr[j]+a[j];
    }
    for(int j=0;j<n;j++){
        l=0,r=j;
        while(l<r){
            md=(l+r)/2;
            if((j-md)*a[j]-fr[j]+fr[md]<=m){
                r=md;
            }else{
                l=md+1;
            }
        }
        ans=max(ans,j-l+1);
    }
    cout<<ans;
}
