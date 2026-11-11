#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[200005],sum,tot;
vector<int> s;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char m;
        cin>>a[i]>>m;
        for(int j=0;j<a[i];j++)
        {
            s.push_back((m-'0'));
        }
        tot+=a[i];
    }
    for(int i=0;i<=tot/2;i++)
    {
        if(s[i]!=s[tot-1-i])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
