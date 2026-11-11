#include <bits/stdc++.h>
using namespace std;
#define int long long
int jz(int a){
    int cnt=0;
    while(a!=0){
        cnt+=a%2;
        a/=2;
    }
    return cnt;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    int b[200005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=jz(a[i]);
    }
    int maxn=-1;
    int maxi=-1;
    for(int i=1;i<=n-m;i++){
        int t=a[i];
        for(int j=i;j<=i+m-1;j++)
        {
            t=t&a[j];
        }
        maxn=max(t,maxn);
    }
    cout<<maxn;
    return 0;
}

