#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int v[N];
int n,m;
int cnt(int w)
{
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		if(v[i]&(1ll<<w)) ans++;	
	}
	return ans; 
}
void gg(int w)
{
	for(int i=1;i<=n;i++) if((v[i]&(1<<w))==0) v[i]=0; 
}
signed main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	int ans=0;
	for(int mask=32;mask>=0;mask--)
	{
		int lzl=cnt(mask);
		if(lzl>=m)
		{
			gg(mask);
			ans+=(1<<mask);
	//		cout<<mask<<endl;
		}
	//	for(int i=1;i<=n;i++) cout<<v[i]<<" ";
	//	cout<<endl;
	}
	cout<<ans;
	return 0;	
}















//fjy I love you!
