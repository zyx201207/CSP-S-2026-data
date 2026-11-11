
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,s=0,ans=INT_MAX;
int a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=max(s,a[i]);
        ans=ans&&a[i];
    }
    if(m==1) cout<<s;
    if(m==n) cout<<ans;
    return 0;
}
