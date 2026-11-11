#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0,c=0;
long long a[200005];
int main{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=i+1;k<=n;k++){

            c=a[i]^a[k+m-2];

           ans=max(ans,c);
        }

    }
    cout<<ans;



    return 0;
}
