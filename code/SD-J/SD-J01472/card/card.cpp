#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[510000],b[510000],c[510000],ans[310000];
string s,ch,y;
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
    	cin>>a[i];
    	s+=a[i]+'0';
	}
	for(i=0;i<n;i++)
	{
		memset(b,0,sizeof(b));
		ch=s.substr(i,n-i+1);
		y=ch;
		for(j=0;j<ch.size();j++)
		{
			if(!b[ch[j]-'0'])
			{
				b[ch[j]-'0']=1;
				c[ch[j]-'0']=j;
			}
			else
			{
				y.erase(c[ch[j]-'0'],j-c[ch[j]-'0']);
				c[ch[j]-'0']=j;
			}
		}
		for(j=0;j<y.size();j++)
		  ans[y[j]-'0']++;
	}
	for(i=1;i<=m;i++)
	  cout<<ans[i]<<" ";
	return 0;
}

