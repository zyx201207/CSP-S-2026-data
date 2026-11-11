#include<bits/stdc++.h>
using namespace std;

typedef int itn;
const int N=200010;
int n,m,a[N];
pair<int,int> cnt[N];

string get_2(int x)
{
	string a;
	while(x)
	{
		a+=x%2+'0';
		x/=2;
	}
	reverse(a.begin(),a.end());
	while(a.size()<=20)
	{
		a='0'+a;
	}
	return a;
}

int times_1(string t)
{
	int sum=0;
	for(itn i=0;i<t.size();i++)
	{
		if(t[i]=='1')sum++;
	}
	return sum;
}

string and_slf(string a,string b)
{
	string c;
	for(int i=0;i<max(a.size(),b.size());i++)
	{
		if(i>=a.size()||i>=b.size())break;
		if(a[i]=='1'&&a[i]==b[i])c+='1';
		else c+='0';
	}
	return c;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(itn i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[i].first=times_1(get_2(a[i])),cnt[i].second=a[i];
	}
	
	sort(cnt+1,cnt+n+1);
	string q=get_2(cnt[n].second);
	for(itn i=n-1;i>n-m;i--)
	{
		string w=get_2(cnt[i].second);
		q=and_slf(q,w);
	}
	int ans=0;
	for(int i=0;i<q.size();i++)
	{
		ans+=(q[i]-'0')*pow(2,q.size()-i-1);
	}
	cout<<ans;
	return 0;
}