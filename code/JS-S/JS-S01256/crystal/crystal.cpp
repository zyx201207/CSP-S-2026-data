#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
long long r(int i,int j){
    return a[j]*(j-i+1)-(s[j]-s[i-1]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int i=1,j=1;
    int ans=0;
    while(i<=j && j<=n){
        long long t=r(i,j);
        if(t<=m){
            ans=max(ans,j-i+1);
            j++;
        }
        else if(t>m){
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
