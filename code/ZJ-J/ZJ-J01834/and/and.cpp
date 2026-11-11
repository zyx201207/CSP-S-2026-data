#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,arr[200010];
	int brr[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+1+n,cmp);
	for(int i=1;i<=n-m+1;i++)
	{
		brr[i]=arr[i];
		for(int j=i+1;j<=i+m-1;j++) brr[i]=(brr[i]&arr[j]); 
		if(1!=i&&brr[i-1]>brr[i])
		{
			cout<<brr[i-1];
			return 0;
		}
	}
	sort(brr+1,brr+2+n-m);
	cout<<brr[n-m+1];
	return 0;
}


