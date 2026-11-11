#include <bits/stdc++.h>
using namespace std;
long long n,len[200005],sum=0,l,r,sl,sr,s=0,les;
char v[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>len[i]>>v[i],sum+=len[i];
    l=len[1],r=len[n],sl=1,sr=n;
    while(sl<=sr)
    {
        les=min(l,r);
        if(v[sl]!=v[sr])
            s+=les;
        l-=les,r-=les;
        if(l==0)
            sl++,l=len[sl];
        if(r==0)
            sr--,r=len[sr];
    }
    cout<<s;
    return 0;
}
