#include <bits/stdc++.h>

using namespace std;
 long long a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    if(m==1){
         long long maxn=-1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    else if(n==m){
        long long ans,x;
        cin>>x;
        ans=x;
        for(int i=1;i<=n-1;i++){
            cin>>a[i];
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==2){
        long long y;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long maxx=-1;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                long long index=a[i]&a[j];
                maxx=max(index,maxx);
            }
        }
        cout<<maxx;
        return 0;
    }
    else{
        return 0;
    }
    return 0;
}
