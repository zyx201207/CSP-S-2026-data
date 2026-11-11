//好想被 OI 折磨成小楠梁
//清秀，灵动，澄澈 
//预期 1~12 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ID,t;
ll n,d;
ll a[2000005];
struct node
{
	int id,step,cnt;
};
void mian1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	vector<int> sum;
	queue<node> q;
	for(int i=1;i<=n+1;i++)
		sum.push_back(0);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;i+j<=n;j++)
			sum[j]=0;
		sum[0]=1;
		q.push(node{i,0,1});
		for(int j=i+1;j<=n;j++)
		{
			while(!q.empty()&&a[q.front().id]+d<a[j])
			{
				sum[q.front().step]-=min(q.front().cnt,3);
				q.pop();
			}
			if(q.empty())
				break;
			if(sum[q.front().step]==2)
				ans++;
			node c=node{j,q.front().step+1,min(sum[q.front().step],3)};
			sum[c.step]+=c.cnt;
			q.push(c);
		}
		while(!q.empty())
			q.pop();
	}
	cout<<ans<<"\n";
}
void mianA()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll len=a[2]-a[1];
	ll k=d/len;
	if(k<=1)
		cout<<0<<"\n";
	else
		cout<<max(n-(2*k-1),0ll)<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ID>>t;
	for(int i=1;i<=t;i++)
	{
		if(11<=ID&&ID<=12)
			mianA();//特殊性质 A 
		else
			mian1();//暴力 
	}
	return 0;
}
