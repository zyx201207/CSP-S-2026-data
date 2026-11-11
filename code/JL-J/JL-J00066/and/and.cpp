#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,maxn=0,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]) sum=a[i];
            else sum=a[i]&&a[j];
            maxn=max(maxn,sum);
        }

    }
    cout<<maxn;
    return 0;
}
