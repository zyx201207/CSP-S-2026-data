#include<bits/stdc++.h>
using namespace std;
long long a[300004];
long long xorxor[300004];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m,maxx=-100000;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        xorxor[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            xorxor[i]=max(xorxor[i],xorxor[i]&j);
        }
    }cout<<xorxor[n];
}
