#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,mid,cnt;
string s,b;
signed main()
{
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++)
    {
        cin>>k>>s;
        for(int j=1;j<=k;j++)
           b=b+s;
    }
    int k=0,l=b.size()-1;
    while(k<l)
    {
        if(b[k]!=b[l])cnt++;
        k++,l--;
    }
    cout<<cnt;
    return 0;
}
