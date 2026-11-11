#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005],d;
bool f=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=d)f=1;
    }
    if(!f){
        int t[500005];
        for(int i=2;i<=n;i++)t[i]=i*(i-1)/2*d;
        if(t[n]<=m)cout<<n;
        for(int i=2;i<=n;i++){
            if(t[i]>m){
                cout<<i-1;
                break;
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long t=0;
        int j=i;
        while(1){
            if(j<1)break;
            t+=a[i]-a[j];
            if(t>m)break;
            j--;
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
