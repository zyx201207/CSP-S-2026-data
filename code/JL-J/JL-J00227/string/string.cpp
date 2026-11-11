#include<bits/stdc++.h>
using namespace std;
string st;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long t;char a;
        cin>>t>>a;
        for(long long j=0;j<t;j++) st+=a;
    }
    string s=st;
    reverse(s.begin(),s.end());
    if(s==st)
    {
        cout<<0;
        return 0;
    }
    else
    {
        if(st.size()%2==0)
        {
            for(long long i=0;i<st.size()/2;i++)
                if(st[i]!=st[st.size()-i-1]) ans++;
            cout<<ans;
        }
        else
        {
            for(long long i=0;i<=st.size()/2;i++)
                if(st[i]!=st[st.size()-i-1]) ans++;
             cout<<ans;
        }
    }
    return 0;
}
