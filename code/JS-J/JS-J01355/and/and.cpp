#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],maxx,s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        s=a[i];
        for(int l=2;l<=m;l++){
            s=s&a[l+i-1];
        }
        if(s>maxx)maxx=s;
    }
    cout<<maxx;
    return 0;
}
