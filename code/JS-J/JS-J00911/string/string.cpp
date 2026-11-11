#include <bits/stdc++.h>
using namespace std;

long long n,a[200010],cnt=0;
char ch[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i] >> ch[i];
    }
    long long l=1,r=n;
    while(l<=r)
    {
        long long d=a[r]-a[l];
        if(d==0)
        {
            if(ch[r]!=ch[l]) cnt+=a[r];
            l++;
            r--;
        }
        if(d>0)
        {
            if(ch[r]!=ch[l]) cnt+=a[l];
            a[r]-=a[l];
            l++;
        }
        if(d<0)
        {
            if(ch[r]!=ch[l]) cnt+=a[r];
            a[l]-=a[r];
            r--;
        }
    }
    cout << cnt << endl;
    return 0;
}
