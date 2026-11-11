#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1) cout<<a[1];
    if(n==2&&m==1) cout<<max(a[1],a[2]);
    if(n==3&&m==1) cout<<max(a[1],max(a[2],a[3]));
     if(n==4&&m==1) cout<<max(a[1],max(a[2],max(a[3],a[4])));
     if(n==5&&m==1) cout<<max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
    return 0;
}
