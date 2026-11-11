#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

int ans=0,n,m;
int A[N];

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>A[i];
    sort(A[i]+1,A[i]+1+n,greater<int>());
    if(m==1)
    {
        cout<<A[1];
        return 0;
    }
    if(m==n)
    {
        int ans=A[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    else cout<<A[m];
    return 0;
}