#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  n;
    cin>>n;
    string st;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(long long i = 1;i<=n;i++)
    {
        long long m;
        char c;
        cin>>m;
        cin>>c;
        for(long long j = 1;j<=m;j++)
        {
            st+=c;
        }
    }
    long long l = st.size();
    long long  cnt = 0;
    for(long long  i = 0;i<=l/2-1;i++)
    {
        if(st[i]!=st[l-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
