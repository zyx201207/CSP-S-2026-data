#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[100000001];

int main()
{   freopen("crystal2.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=1;
    for(int i=1;i<=n;i++){
        if(m<0) break;
        if(a[i+1]-a[i]<=m){
            m=m-a[i+1]-a[i];
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
