#include<bits/stdc++.h>
using namespace std;
long long a[10000000],s[10000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<n;i++){
        s[i]=abs(a[i]-a[i+1]);
    }
    n--;
    long long ans=0;
    for(long long i=n;i>=1;i--){
        for(long long j=i;j>=1;j--){
            ans=+a[i]-a[j];
        }
        if(ans<=m){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
