#include<bits/stdc++.h>
using namespace std;
long long m,n,cw[500861],ans=1,i,j,q,d[500861],pre,mn,bl=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>cw[i];
	}
	sort(cw,cw+n);
	for(i=1;i<n;i++){
		d[i]=cw[i]-cw[i-1];
	}
	if(n<=5)
	{
		for(i=1;i<n;i++)
		{
			pre=1;
			mn=m;
			while(pre*d[i+pre-1]<=mn&&(i+pre-1)<n)
			{
				mn=mn-pre*d[i];
				pre=pre+1;
			}
			ans=max(pre,ans);
		}
	}
	else if(n>5)
	{
		for(i=2;i<n;i++)if(d[i]==d[1])bl++;
		if(bl==n-1){
		j=m/d[1]*2;
		ans=min((long long)((sqrt(j+0.25))+0.5),n);
		}
		else
		{
			for(i=1;i<n;i++)
			{
			pre=1;
			mn=m;
			while(pre*d[i+pre-1]<=mn&&(i+pre-1)<n)
			{
				mn=mn-pre*d[i+pre-1];
				pre=pre+1;
			}
			ans=max(pre,ans);
		}
		}
	}
	cout<<ans<<endl;
	return 0;
}
