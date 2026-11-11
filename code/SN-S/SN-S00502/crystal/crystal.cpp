//郭曹成 爱知中学 SN-S00502
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	
	int sum=1,ans=0,f=0,v=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			sum++;
			continue;
		}
		else
		{
			
			v=i-1;
			
			
			if(sum!=ans){
			
				ans=max(ans,sum);
				f=a[i-1];
			}
			i+=sum-1;
			sum=1;
		}					
	}
	
	if(m==0)
	{
		cout<<ans;
		return 0;
	}
	else{
		int k=m;
		for(int i=0;i<v;i++){
			if(a[i]+k>=f&&a[i]<f)
			{
				k=a[i]+k-f;
				ans++;	
			}		
		}
		cout<<ans;
	}
	return 0;
} 
