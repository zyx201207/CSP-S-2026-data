#include <bits/stdc++.h>
using namespace std;

int n,m;
/*int a[200010];
int one[200010];*/
struct ahaha
{
	int a;
	int one;
}mei[200010];

string search(int point)
{
	int gunmu=mei[point].a;
	string res="";
	while(gunmu<=0)
	{
		res+=to_string(gunmu-gunmu/2);
		gunmu-=gunmu/2;
	}
	return res;
}
bool cmp(ahaha x,ahaha y)
{
	return x.one>y.one;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>mei[i].a;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		string res=search(i);
		for(int j=0;j<res.size();j++)
		{
			if(res[i]=='1') cnt++;
		}
		mei[i].one=cnt;
	}
	sort(mei+1,mei+1+n,cmp);
	int ans=0;
	for(int i=1;i<m;i++)
	{
		ans=mei[i].a&mei[i+1].a;
	}
	cout<<ans;
	return 0;
}
