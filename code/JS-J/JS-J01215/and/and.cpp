#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,minx;
long long a[2000010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    int maxn=0;

    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>=maxn)maxn=a[i];
        }
        cout<<maxn;return 0;
    }

    else if(m==n){
        for(int i=2;i<=n;i++){
            ans+=a[i-1]&a[i];
        }
        cout<<ans;return 0;
    }
    else {
        for(int i=n;i>=1;i--){
            if(a[i]>=maxn)maxn=a[i];
            else if(a[i]<maxn&&a[i]>minx)minx=a[i];
        }
        int y=maxn&minx;
        cout<<y;
    }
    return 0;
}
