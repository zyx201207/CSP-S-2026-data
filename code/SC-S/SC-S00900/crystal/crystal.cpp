#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int T = 1e5 + 10; 

bool delta1 = true;
bool isdelta = true;
int delta;
int n,m;
map <int,int> mp; 
int ans = -10000000,counter = 1;

int a[N];

int sum(int fi,int en,int d)
{
	return ((en - fi)/d+1)*(fi+en)/2;
}

void dfs(int s,int k)
{
	if(counter > T)
	{
		cout<<ans;
		exit(0);
	}
	if(s == n+1 || k == 0)
	{
		++ counter;
		for(int i=1;i<=n;i++)
		{
			int l = mp.size();
			for(int i=-100;i<=100;i++)
			{
				ans = max(ans,mp[i]);
			}
		}
		return ;
	}
	
	for(int i=0;i<=k;i++)
	{
		mp[a[s]] -= 1;
		mp[a[s] + i] += 1;
		
		dfs(s+1,k-i);
		
		mp[a[s]] += 1;
		mp[a[s] + i] -= 1;
	}
}


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>a[1]; 
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		
		//map
		mp[a[i]] += 1;
		
		if(a[i]-a[i-1] != 1)
		   delta1 = false;
		
		if(i == 2)
		{
			delta = a[i] - a[i-1];
		}else{
			if(a[i] - a[i-1] != delta)
			   isdelta = false;
		}
		   
	}
	if(delta1)//公差为 1 
	{
		//最优情况
		if(m >= (1+a[n-1])*(n-1)/2)
		{
			cout<<n;
		}
		//普通
		else{
			dfs(1,m);
			cout<<ans;
			return 0;
		} 
	}else if(isdelta)
	{
		//最优情况
		if(m >= sum(delta,a[n]-a[1],delta))
		{
			cout<<n;
		}
		//普通情况
		else
		{
			dfs(1,m);
			cout<<ans;
			return 0; 
		} 
	}else{
		dfs(1,m);
		cout<<ans;
		return 0;
	}

	
	return 0;
 }  