#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string s;
long long n,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char ch;
        cin>>a[i];
        cin>>ch;
        s+=ch;
    }
    int l=0,r=n-1;
    while (l<r)
    {
        long long minn=min(a[l],a[r]);
        if (s[l]!=s[r])
        {
            ans+=minn;
        }
        a[l]-=minn;
        a[r]-=minn;
        if(a[l]==0) l++;
        if(a[r]==0) r--;

    }
    cout<<ans;
    return 0;
}
