#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[500005],ans=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			int sum=0,t=0;
		    sum=a[j]*(j-i+1);
		    for(int s=i;s<=j;s++)
		    {
		    	t=t+a[s];
			}
			t=t+m;
			if(t>=sum)
			ans=max(ans,j-i+1);
		}
		
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
