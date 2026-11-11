#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n+5];
    long long pre[n+5];
    pre[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        long long sum=0;
        for(int i=1;i+mid-1<=n;i++){
            sum=1ll*mid*a[i+mid-1]-pre[i+mid-1]+pre[i-1];
            if(sum<=m){
                break;
            }
        }
        if(sum>m) r=mid;
        else l=mid+1;
    }
    cout<<l-1;
    return 0;
}
