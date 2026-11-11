#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5*1e5+1;
long long arr[N],cha[N];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	bool flag=1;
	for(int a=0;a<n;a++)
	{
		cin>>arr[a];
		if(arr[a]!=arr[a-1]&&a>0)
			flag=0;
	}
	if(flag)
	{
		cout<<n;
		return 0;
	}
		
	
	sort(arr,arr+n);
	int ans_m=0;
	for(int a=1;a<n;a++)
	{
		int i=0;
		int ji=0;
		int ans=0;
		for(;i<=a;i++)
		{
			cha[i]=arr[a]-arr[i];
			if(cha[i]==0)
				ans++;
		}
		sort(cha,cha+i);
		for(int b=0;b<i;b++)
		{
			if(ji>=m)
				break ;
			ji+=cha[b];
			if(cha[b])
				ans++;
			
		}
		ans_m=max(ans_m,ans);
	}
	cout<<ans_m;
	
	return 0;
} 
