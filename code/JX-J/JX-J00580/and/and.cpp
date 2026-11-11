#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],t,d=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        for(int j=i+1;j<=n-m+1;j++){
            t=a[i];
            for(int k=j;k<=m+j-1;k++){
                t=t&a[j];
            }
            d=max(d,t);
        }
    }
    return 0;
}