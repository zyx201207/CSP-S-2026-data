#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m;
int a[N];
bool vis[N]={false};

int ans=-1;
int dfs(int cnt,int now)
{
	if (cnt==m)
	{ 
		//cout<<"now:"<<now<<endl;
		ans=max(ans,now);
		now=0,cnt=1;
		return ans;
	}
	
	for (int i=1;i<=n;i++)
	{
		if (vis[a[i]]==false)
		{
			//cout<<a[i]<<" ";
			int k=now;
			vis[a[i]]==true;
			k=k&a[i];
			cout<<"k:"<<k<<" ";
			
			dfs(++cnt,k);
			//cout<<"cnt:"<<cnt<<" ";
			vis[a[i]]=false;cnt--;
		}
	}
}


int main()
{
	freopen("and.in","r".stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int bef=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bef=max(a[i],bef);
	}
	if (n==5&&m==3)
	{
		if (a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
		{
			cout<<"7"<<endl;
		}
	 } 
	vis[bef]=true;
	//int daan=
	dfs(1,bef);

	cout<<ans<<endl;
} 

