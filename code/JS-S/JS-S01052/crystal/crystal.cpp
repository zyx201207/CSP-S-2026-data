#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=0,r=n;
    while(l+1<r){
        int mid=(l+r)/2,f=0;
        for(int i=1;i+mid-1<=n;i++){
            if(a[i+mid-1]*mid-(sum[i+mid-1]-sum[i-1])<=m){
                f=1;
                break;
            }
        }
        if(f){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}
