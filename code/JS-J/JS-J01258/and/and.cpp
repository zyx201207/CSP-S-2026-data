#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,m,ans;
vector<int>a;
void dg(int dep,int s,int l){
    if(dep>m){
        ans=max(ans,s);
        return;
    }
    for(int i=l+1;i<=n;i++){
        int t=s;
        s=a[i]&s;
        dg(dep+1,s,i);
        s=t;
    }


}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    a.resize(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dg(1,2147483647,0);
    cout<<ans;
    return 0;
}
