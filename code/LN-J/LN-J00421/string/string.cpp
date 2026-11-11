#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],cnt;
char b[N];
char ss[10000000],s[10000000];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int len=0,ind=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        len+=a[i];
        for(int j=ind;j<ind+a[i];j++)
        {
            ss[j]=b[i];
            s[j]=b[i];
        }
        ind=ind+a[i];
    }
    reverse(s,s+len);
    for(int i=0;i<ind;i++)
        if(ss[i]!=s[i])cnt++;
    cout<<cnt/2;
    return 0;
}
