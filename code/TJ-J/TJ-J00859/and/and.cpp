#include <bits/stdc++.h>
using namespace std;
int a[200005];
int cmp(int x,int y)
{
	return x>y; 
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,sum,summ,k=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	summ=-1;
	for(i=2;i<=n;i++)
	{
		if(a[i]<=sum/2 && (sum-a[i])%2==0)
		{
			k++;	
			sum=max(sum&a[i],summ);
			if(summ==sum) summ=-1;
		}
		else if(a[i]>sum/2)
		{
			k++;
			sum=max(sum&a[i],summ);
			if(summ==sum) summ=-1;
		}
		else if(a[i]<=sum/2 && (sum-a[i])%2==1)
		{
			summ=sum&a[i];
		}
		if(k==m)
			break;
	}
	cout<<sum;
	return 0;
}

