#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans=0,h=0,mid=0;
bool isa=false,isb=false;

bool cmp(int x,int y)
{
	return x<y;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h+=a[i];
	}

	mid=h/n;
	
	vector<int> sum(n+1);
	for(int i=1;i<=n;i++) sum[i]=abs(mid-a[i]);
	sort(sum.begin(),sum.end(),cmp);
	bool f=true;
	for(int i=1;i<=n+1;i++)
	{
		if(m-sum[i]>=0) m=m-sum[i],ans++;
		else
		{
			f=false;
			break;
		}
	} 
			

	while(m && f)
	{
		m/=n;
		ans++;
	}
		
	cout<<ans;
	
	return 0;
}
