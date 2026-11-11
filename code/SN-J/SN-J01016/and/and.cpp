#include<iostream>
#include<vector>
#define int long long
using namespace std;
int a[5000005];
bool used[5000005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
			used[i]=1;
	}
	
	for(int i=30;i>=0;i--)
	{
		//考虑第k位。排序。保留前k
		//?
		 vector<int> live;
		for(int j=0;j<n;j++)
		{
			if(!used[j])continue;
			if(a[j]<(1<<i))continue;
			if((a[j]>>i)&1)live.push_back(j);
		}
		if(live.size()<m)
		{//cout<<"n";
		//没有办法
		live.clear();
		for(int j=0;j<n;j++)
		{
			if(!used[j])continue;
			live.push_back(j);
		}
		 
			
		}
		//cout<<(1<<i)<<' '<<live.size()<<endl;
		
		for(int j=0;j<n;j++){used[j]=0;}
		 
		for(auto _:live)
		{
			used[_]=1;
			
		}
	}
	
	int ans=-1;
	
		for(int j=0;j<n;j++)
		{
			if(!used[j])continue;
			//cout<<a[j]<<' ';
			if(ans==-1)ans=a[j];
			else ans=ans&a[j];
		}
		
		cout<<ans;
}
 
