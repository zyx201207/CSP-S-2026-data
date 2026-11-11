#include<bits/stdc++.h>
using namespace std;
int n,m;
string ans;
int a[200005];
struct node
{
	string s;
	int d,k;
}str[200005];
node to(int o)
{
	char s1[40];
	string s2;
	int i=0,cnt=0;
	while(o>0)
	{
		s1[++i]=char(o%2+'0');
		o/=2;
		if(s1[i]=='1')  cnt++;
	}
	for(int j=1;j<=i;j++)
		s2+=s1[i-j+1];
	return {s2,cnt,o};
}
bool cmp(node x,node y)
{
	if(x.d!=y.d)  return x.d>y.d;
	return x.s.size()>y.s.size();
}
string yu(string s1,string s2)
{
	int sl=max(s1.size(),s2.size());
	string s3,s4,s0;
	char ts[50]={};
	for(int j=1;j<=s1.size();j++)
		s3+=s1[s1.size()-j+1];
	for(int j=1;j<=s2.size();j++)
		s4+=s2[s2.size()-j+1];
	for(int i=1;i<=sl;i++)
	{
		if(s3[i]=='1'&&s4[i]=='1')  ts[i]='1';
		else  ts[i]='0';
	}
	for(int j=1;j<=sl;j++)
		s0+=ts[sl-j+1];
	return s0;
}
int m2(int x)
{
	if(x==0)  return 1;
	return 2*m2(x-1);
}
int ten(string s)
{
	int cnt=0;
	for(int i=1;i<=s.size();i++)
		if(s[i]=='1')
			cnt+=m2(s.size()-i-1);
	return cnt;
}

int main()
{
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].k;
		str[i]=to(str[i].k);
	}
	sort(str+1,str+n+1,cmp);
	ans=" "+str[1].s;
	for(int i=2;i<=m;i++)
	{
		ans=yu(ans," "+str[i].s);
	}
	cout<<ten(ans);
	return 0;
}