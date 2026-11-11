#include<bits/stdc++.h>//SN-S00495 闫可心 陕西省西安中学 
using namespace std;
typedef long long LL;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	LL m,mx=-1;
	cin>>n>>m;
	LL a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		LL sum=0,num=0;
		for(int j=i-1;j>=0;j--)
		{
			sum+=a[i]-a[j];
			num++;
			if(sum==m)
			{
				mx=max(mx,num+1);
				break;
			}
			else if(sum>m)
			{
				mx=max(mx,num);
				break;
			}
		}
	}
	cout<<mx<<'\n';
	return 0;
}
