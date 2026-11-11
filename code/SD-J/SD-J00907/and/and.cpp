#include <bits/stdc++.h>
#define CHECK_SIZE(x) cout<<#x<<": "<<sizeof(x)%1024<<"B "<<sizeof(x)%(1024*1024)/1024<<"KB "<<sizeof(x)/1024/1024<<"MB\n"
using namespace std;
const int N=2e5+7;
using uint=uint32_t;
int n,m,cnt[64];
uint a[N];
bool del[N];
void check_size()
{
	CHECK_SIZE(cnt);
	CHECK_SIZE(a);
	CHECK_SIZE(del);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
//	check_size();
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=30;j++)
			if((a[i]>>j)&1)
				cnt[j]++;
	}
	
	uint ans=0;
	for(int i=30;i>=0;i--)
	{
		if(cnt[i]<m)
			continue;
		ans|=1U<<i;
		for(int j=1;j<=n;j++)
		{
			if((a[j]>>i)&1)
				continue;
			if(del[j])
				continue;
			del[j]=true;
			for(int k=0;k<=30;k++)
				if((a[j]>>k)&1)
					cnt[k]--;			
		}
	}
	cout<<ans;
		 
	return 0;
} 
