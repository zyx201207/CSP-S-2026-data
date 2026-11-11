//- Enchrance of the Chaos -
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
//int a[N];
int size;
struct node
{
	vector<int>qwq;
	int l;
	int a;
}b[N];
vector<node>nu;
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int ans=INT_MAX;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
//		cin>>a[i];
		int a;
		cin>>a;
		b[i].a=a;
		while(a>0)
		{
			b[i].qwq.push_back(a%2);
			a/=2;
		}
		b[i].l=b[i].qwq.size();
	}
	for(int len=31;len>=1;len--)
	{
		int cnt=0;
		nu.clear();
		for(int i=1;i<=n;i++)
		{
			if(b[i].l>=len&&b[i].qwq[len-1]==1)
			{
				cnt++;
				nu.push_back(b[i]);
			}
		}
		if(cnt>=m)
		{
			size=len;
			break;
		}
	}
//	cout<<size;
	for(int j=0;j<nu.size();j++)
	{
//		cout<<nu[j].a<<"\n";
		int x=0;
		int y=1;
		for(int i=0;i<size;i++)
		{
			x+=nu[j].qwq[i]*y;
			y*=2;
		}
		nu[j].a=x;
	}
	sort(nu.begin(),nu.end(),cmp);
	for(int i=0;i<m;i++)
	{
		ans&=nu[i].a;
//		cout<<nu[i].a<<"\n";
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}