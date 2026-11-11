#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    long long a;
	char c;
}s[200010];
int n,l,r;
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }
    l=1,r=n;
    while(1)
    {
        if(s[l].a>s[r].a)
        {
            if(s[l].c==s[r].c)s[l].a-=s[r].a,r--;
            else cnt+=s[r].a,s[l].a-=s[r].a,r--;
        }
        else if(s[l].a<s[r].a)
        {
            if(s[l].c==s[r].c)s[r].a-=s[l].a,l++;
            else cnt+=s[l].a,s[r].a-=s[l].a,l++;
        }
        else
        {
            if(s[l].c==s[r].c)l++,r--;
            else cnt+=s[l].a,l++,r--;
        }
        if(r<=l)return cout<<cnt,0;
    }
    return 0;
}
