#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=2e5;
int a[MAXN];
int b[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }

    sort(a+1,a+n+1);

    cout<<a[n-m+1];
    return 0;
}
