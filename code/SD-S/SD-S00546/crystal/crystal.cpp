#include<bits/stdc++.h>
using namespace std;
long long nn,mm;
const int N=5e5+10;
long long aa[N],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>nn>>mm;
	long long id;
	long long minn=INT_MAX;
	for(int i=1;i<=nn;i++) cin>>aa[i];
	sort(aa+1,aa+nn+1); 
	for(int i=1;i<=nn;i++)
	{
		int xx=aa[i],ans=0;
		for(int j=1;j<=nn;j++)
		{
			ans+=abs(aa[j]-xx);
		}
		if(ans<minn)
		{
			minn=ans;
			id=aa[i];
		}
	}
	priority_queue<long long> qq;
	int tt=0;
	while(aa[++tt]<=id)
	{
		int uu=id-aa[tt];
		qq.push(uu);
		if(mm-uu>=0) mm-=uu,ans++; 
		else
		{
			if(!qq.empty())
			{
				int xx=qq.top();
				qq.pop();
				mm=mm+xx-uu; 
			}
		}
	}
	cout<<ans;
	return 0;
}


