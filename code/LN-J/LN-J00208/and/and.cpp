#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long a[n+10]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maxn=max(maxn,a[i]&a[j]);
        }
    }
    cout<<a[n];
    return 0;
}
