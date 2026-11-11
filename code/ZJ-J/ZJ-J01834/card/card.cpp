#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int arr[5001],brr[5001],crr[5001],n,m,drr[5001]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		memset(brr,0,sizeof(brr));
		memset(crr,0,sizeof(crr));
		for(int j=i;j<=n;j++)
		{
			if(crr[arr[j]]==1){
				for(int k=drr[arr[j]];k<=j;k++) {
					crr[brr[k]]=0;
					brr[k]=0;
				}
			}
			crr[arr[i]]=1;
			brr[j]=arr[j];
			drr[brr[j]]=j;
		}
		for(int j=i;j<=n;j++) drr[brr[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<drr[i]<<" ";
	
	return 0;
}
