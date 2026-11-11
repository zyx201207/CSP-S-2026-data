#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int z[200010][33];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    if(m==1) cout<<a[n];
    else{
        cout<<a[n+1-m];
    }
    return 0;
}

