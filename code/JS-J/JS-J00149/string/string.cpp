#include<bits/stdc++.h>
using namespace std;
int n;
string a;
bool tong[206];
int anss=999999;
bool check(string s)
{
    for(int i=0;i<=s.length()/2-1;i++)
    {
        if(s[i]!=s[s.length()-1-i])
            return false;
    }
    return true;
}
void dfs(string s,int cnt)
{
    if(check(s))
    {
        int ans=0;
        for(int i=0;i<=s.length()-1;i++)
        {
            if(a[i]!=s[i])
            ans++;
        }
        anss=min(ans,anss);
        return;
    }
    if(cnt==s.length())
        return;
    for(int i=1;i<=26;i++)
    {
        if(
           tong[i-1]==true)
        {
            string ss=s;
            ss[cnt]='a'+i-1;
            //cout<<ss<<" ";
            dfs(ss,cnt+1);
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int temp;
        char c;
        cin>>temp>>c;
        tong[c-'a']=true;
        for(int i=1;i<=temp;i++)
        {
            a+=c;
        }
    }
    dfs(a,0);
    cout<<anss;
    return 0;
}
