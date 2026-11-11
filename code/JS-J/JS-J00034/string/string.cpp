#include<bits/stdc++.h>
using namespace std;
long long n,len,cnt,ntr,ans,l,r;
vector<long long> a;
vector<char> c;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    a.resize(n+1);
    c.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    for(long long l=1,r=n;l<r;)
    {
        if(c[l]!=c[r]) ans+=min(a[l],a[r]);
        if(a[l]>a[r])
        {
            a[l]-=min(a[l],a[r]);
            r--;
        }
        else
        {
            a[r]-=min(a[l],a[r]);
            l++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
