#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=INT_MIN;
int two_ten(string s)
{
    int r=1,sum=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        sum+=(s[i]-'0')*r;
        r*=2;
    }
    return sum;
}
string ten_two(int n)
{
    char x;
    string s;
    while(n!=0)
    {
        x=(n%2+'0');
        s=s+x;
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
string andd(string a,int b)
{
    string bb=ten_two(b),c="";
    int ll=min(a.size(),bb.size());
    for(int i=ll-1;i>=0;i--)
    {
        if(a[i]==bb[i] && a[i]=='1') c+='1';
        else c+='0';
    }
    reverse(c.begin(),c.end());
    return c;
}
void kevin(int cnt,string sum,int l)
{
    if(cnt==m)
    {
        maxn=max(maxn,two_ten(sum));
        return;
    }
    for(int i=l;i<=n;i++)
    {
        if(cnt==0) kevin(cnt+1,ten_two(a[i]),i+1);
        else kevin(cnt+1,andd(sum,a[i]),i+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    kevin(0,"",1);
    cout<<maxn;
    return 0;
}
