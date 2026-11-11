#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a,jin,cun=0,md,ans1=0,qc,hc,sum=0;
	cin>>a;
	long long arr[a];
	char crr[a];
	for(int i=0;i<a;i++)
	{
		cin>>jin;
		cun+=jin;
		arr[i]=cun;
		cin>>crr[i];
	}
	md=(cun+1)/2;
	int ans2=a-1;
	qc=crr[0];
	hc=crr[a-1];
	for(int i=1;i<=md;i++)
	{
		if(i>arr[ans1])
		{
			ans1++;
			qc=crr[ans1];
		
		
		}
		if((cun-i+1)<arr[ans2-1]+1)
		{
			ans2--;
			hc=crr[ans2];
		}
		if(qc!=hc)sum++;
	}
	cout<<sum;
	return 0;
}
