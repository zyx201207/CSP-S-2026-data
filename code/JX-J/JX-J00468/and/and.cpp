#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx,la,lb,zs;
string a1,b1,ds;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mx=max(x,mx);
    }
    cout<<mx;
    return 0;
}

