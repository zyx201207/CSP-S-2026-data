#include<bits/stdc++.h>
using namespace std;
int n,m,mx=-1;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        int ad=a[i];
        for(int x=i+1;x<=i+m-1;x++){
            ad=ad&a[x];
        }
        mx=max(mx,ad);
    }
    cout<<mx;
    return 0;
}
