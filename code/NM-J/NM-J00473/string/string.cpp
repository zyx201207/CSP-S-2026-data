#include <bits/stdc++.h>
using namespace std;
int n,pos;
string s,t2,t1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s=" "+s;
    for (int i=1;i<=n;i++)
    {
        int x;
        string c;
        cin>>x>>c;
        pos+=x;
        for (int j=1;j<=x;j++)  s+=c;
    }
    int k=pos/2;
    t1=s.substr(1,k);
    if (k%2==0)  t2=s.substr(k+1,k);
    else    t2=s.substr(k+2,k);
    int len=t2.size();
    int ans=0;
    for (int i=0;i<len;i++)
    {
        if (t1[i]!=t2[len-1-i])   ans++;
    }
    cout<<ans;
    return 0;
}
