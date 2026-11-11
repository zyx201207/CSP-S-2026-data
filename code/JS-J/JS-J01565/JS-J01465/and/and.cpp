#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long b[200005];
long long cnt;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(b[a[i]]==0) b[a[i]]=1;
        else cnt=a[i]
    }
    sort(a+1,a+n+1);
    cnt=a[1];
    if(m=1) cout<<a[1];
    else if(cnt>0) cout<<cnt;
    else{
        for(int i=1;i<=n;i++)
        {
            cnt&=a[i];
        }
        cout<<cnt;
    }
    return 0;
}
