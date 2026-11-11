#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
long long c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n+1;i++){
        c[a[i]]=i;
        if(a[i]!=a[i-1]) b[a[i-1]]=i-1;
    }
    if(n==m){
        for(int i=1;i<=n;i++){
            cout<<c[i]<<" ";
        }
    }
    else{
        for(int i=1;i<=m;i++){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
