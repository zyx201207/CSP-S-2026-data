#include<bits/stdc++.h>
using namespace std;
struct INFO
{
	int num;
	string two;	
};
INFO a[1000010];
string x(int t)
{
	string s="";
	while(t>0)
	{
		s+='0'+t%2;
		t/=2;
	}
	int l=s.size();
	for(int i=1;i<=30-l;i++) s+='0';
	reverse(s.begin(),s.end());
	return s;
}
bool cmp(INFO p,INFO q)
{
	for(int i=1;i<=30;i++)
	{
		if(p.two[i]!=q.two[i]) return p.two>q.two;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].num;
		a[i].two=x(a[i].num);
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].num;
	for(int i=1;i<=m;i++)
	{
		ans=ans&a[i].num;
	}
	cout<<ans;
	return 0;
} 
