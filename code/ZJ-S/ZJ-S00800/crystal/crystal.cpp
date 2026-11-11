#include<bits/stdc++.h>
using namespace std;
int n,ans,b;
long long m,a[500005],s[500005],cnt;
void qsort(int l,int r)
{
	int i=l,j=r,mid=(l+r)>>1;
	do{
		while(s[i]<a[mid])  i++;
		while(s[j]>a[mid])  j--;
		if(i<=j)
		{
			swap(s[i],s[j]);
			i++,j--;
		}
	}while(i<=j);
	if(l<j)  qsort(l,j);
	if(i<r)  qsort(i,r);
}
bool cmp(long long x,long long y)
{
	if(x!=0&&y!=0)
		return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=(1+n)/2;
	int minc=-1;
	for(int j=1;j<=n;j++)  s[j]=a[j]-a[mid];
	sort(s+1,s+n+1);
//	qsort(1,mid);
	sort(s+1,s+mid+1,cmp);
	int k=1;
	ans=1;
	while(k<=mid&&m>0)
	{
		if(m>=abs(s[k]))  m-=abs(s[k]),ans++,s[k]=0;
		k++;
	}
	k=1;
	while(a[mid+k]==a[mid])  ans++,k++;
	while(m>=(s[mid+k]-s[mid+k-1])*ans&&ans<n){
		m-=ans*(s[mid+k]-s[mid+k-1]);ans++;k++;
	}
	cout<<ans;
	return 0;
}