#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],h[500005]={},s[500005]={};
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1])      h[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        h[i]++;
    }
    for(int i=1;i<=m;i++){
        s[i]=s[i-1]+h[i];
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<' ';
    }
    return 0;
}
