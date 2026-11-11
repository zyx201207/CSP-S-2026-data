#include<bits/stdc++.h>
using namespace std;
int n,m,mi,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    sort(a+1,a+n);
    for(int i=1;i<=n;i++){
    mi=min(mi,a[i]);
    }
    if(mi>m)  {
    cout<<"1";
    return 0;
    }
    cout<<m;
    return 0;
}
