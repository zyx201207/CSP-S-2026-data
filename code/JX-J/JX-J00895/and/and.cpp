#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,sum,ans;
int a[N],b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        b[i]=a[i] & a[i+1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(b[i]>ans) swap(b[i],ans);
    }
    cout<<ans;
    return 0;
}