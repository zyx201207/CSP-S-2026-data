#include<iostream>
#define Maxn 500005
#define Maxm 300005
namespace my
{
	using std::cin;
	using std::ios;
	using std::cout;
}
using namespace my;
int n,m;
int card[Maxn];
int count[Maxm];
int last[Maxm];
void play(int start)
{
	for(int i=1;i<=m;++i)
	{
		last[i]=-1;
	}
	for(int i=start;i<=n;++i)
	{
		if(last[card[i]]==-1)
		{
			last[card[i]]=i;
		}
		else
		{
			for(int j=last[card[i]];j<i;++j)
			{
				last[card[j]]=-1;
			}
			last[card[i]]=i;
		}		
	}
	for(int i=1;i<=m;++i)
	{
		if(last[i]!=-1)
		{
			++count[i];
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>card[i];
	}
	for(int i=1;i<=n;++i)
	{
		play(i);
	}
	for(int i=1;i<=m;++i)
	{
		cout<<count[i]<<' ';
	}
	return 0;
}
