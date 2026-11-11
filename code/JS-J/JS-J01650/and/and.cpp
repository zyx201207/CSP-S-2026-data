#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
string a[N];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        string s;
        while(t!=0)
        {
            s=s+char(t%2+48);
            t/=2;
        }
        a[i]=s;
        int tt=s.size();
        maxx=max(maxx,tt);
    }
    for(int i=1;i<=n;i++) while(a[i].size()<maxx) a[i]=a[i]+'0';
    string ans;
    vector<string> cur;
    for(int i=1;i<=n;i++) cur.push_back(a[i]);
    for(int i=maxx-1;i>=0;i--)
    {
        int cnt=0;
        vector<string> t;
        for(string s:cur)
        {
            //cout<<s<<' ';
            if(s[i]=='1')
            {
                cnt++;
                t.push_back(s);
            }
        }
        if(cnt>=m)
        {
            ans+='1';
            cur.clear();
            for(string s:t) cur.push_back(s);
        }
        else
        {
            ans+='0';
            t.clear();
        }
        //cout<<'\n';
    }
    int t=0;
    int ansize=ans.size();
    for(int i=ansize-1,j=1;i>=0;i--,j*=2) t+=(ans[i]-'0')*j;
    cout<<t;
    return 0;
}
//OMG i did this!
