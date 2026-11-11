#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n+1];
    int ans[m+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        ans[i]=0;
    }
    for(int i=1;i<n;i++){
        int q=1;
        if(a[i]==a[i+1]){
            ans[q]++;
        }
        else{
            ans[q]++;
            ans[q+1]=ans[q];
            q++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
    }
    return 0;
}
