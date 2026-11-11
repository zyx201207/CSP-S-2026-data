#include<bits/stdc++.h>
using namespace std;
long long a[200009],n,m,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    if(m==1){
            cout<<0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans;
    return 0;
}
