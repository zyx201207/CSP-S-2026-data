#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxn;
const int N=2e5+5;
int a[N];
string s[N];
string to_(int a)
{
    string s1="";
    int i=0;
    while(a)
    {
        s1+=char(a%2+'0');
        a/=2;
        i++;
    }
    return s1;
}
bool cmp(string s1,string s2)
{
    if(s1.size()!=s2.size())
        return s1.size()>s2.size();
    for(int i=s1.size()-1;i>=0;i--)
    {
        if(s1[i]!=s2[i])
            return s1[i]>s2[i];
    }
    return s1[0]>s2[0];
}
string and_(string s1,string s2)
{
    string s3="";
    if(s1.size()>s2.size())
        return and_(s2,s1);
    int len_max=s1.size();
    int len_min=s2.size();
    for(int i=0;i<len_min;i++)
    {
        if(s1[i]=='1'&&s2[i]=='1')
        {
            s3+='1';
        }
        else
        {
            s3+='0';
        }
    }
    for(int i=len_min;i<=len_max-1;i++)
    {
        s3[i]='0';
    }
    return s3;
}
void out_(string ans)
{
    int sum=0;
    for(int i=0;i<ans.size();i++)
    {
        sum+=int(ans[i]-'0')*pow(2,i);
    }
    cout<<sum;
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=to_(a[i]);
        maxn=max(maxn,a[i]);
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    sort(s+1,s+n+1,cmp);
    string ans=s[1];
    for(int i=2;i<=m;i++)
    {
        ans=and_(s[i],ans);
    }
    out_(ans);
    return 0;
}
