#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long ml=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int l=n;l>=1;l--){
        if(ml>=l)break;
        long long sum=0,x=1;
        for(int i=l-1;i>=1&&(sum+a[l]-a[i])<=m;i--){
            sum+=a[l]-a[i];
            x++;
        }
        ml=max(ml,x);
    }
    cout<<ml;
    return 0;
}
