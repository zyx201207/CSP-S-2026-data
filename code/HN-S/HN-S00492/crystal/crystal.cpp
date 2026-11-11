#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m;
void Work(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long need=0;
    int l=1,ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,i-l+1);
        need+=(i-l+1)*(a[i+1]-a[i]);
        while(need>m){
            need-=a[i+1]-a[l];
            l++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Work();
    }
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/