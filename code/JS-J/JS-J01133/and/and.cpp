#include<bits/stdc++.h>
using namespace std;
long long a[200005],s[200005];
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    s[m-1]=1;
    a[0]=1;
    for(int i=1;i<=n-m+1;i++){
        long long now=a[i];
        for(int j=i+1;j<i+m;j++){
            now=now&a[j];
        }
        s[i]=now;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(s[i],ans);
    }
    cout<<ans;
    return 0;
}
