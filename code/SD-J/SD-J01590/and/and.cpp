#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream> 
#define MAXN 200100
using namespace std;
int a[MAXN]; 
bool bit[MAXN][33];//第i个数二进制j位是几 
bool f[MAXN];//这个数有没有被用过 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<31;j++)
		{
			bit[i][31-j]=(a[i]>>j)&1;
			if((a[i]>>j)==0) break;	
			k=max(j+1,k);
		}
	}
	//cout<<k;
	unsigned int x=1LL<<31;
	int ans=0;
	bool f1=false;//是否已经产生过选数 
	for(int j=31-k+1;j<=31;j++)//第i位 
	{
		int sum=0;//已经选过的这一位是1的个数
		vector<int> q;
		for(int i=1;i<=n;i++)
		{
			if(bit[i][j]==1&&(f1==false||f[i]==true)){
				sum++;
				if(f1==false){
					f[i]=true;
				}
			}
			if(f[i]==true&&bit[i][j]==0)
			{
				q.push_back(i);
			}
		} 
		if(sum>=m)
		{
			ans+=(x>>j);
			if(f1==false)
			{
				f1=true;
			}
			for(int mn=1;mn<=q.size();mn++)
			{
				f[q[mn-1]]=false;
			}
			q.clear();
		}
	}
	cout<<ans;
	return 0;
}
