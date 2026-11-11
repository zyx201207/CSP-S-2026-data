#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
using namespace std;
char b[200010];
long long ans,a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)    cin>>a[i]>>b[i];
	for(int i=1,j=n;i<j;)
	{
		if(a[i]>a[j])
		{
			if(b[i]!=b[j])    ans+=a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		else if(a[i]<a[j])
		{
			if(b[i]!=b[j])    ans+=a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
		else
		{
			if(b[i]!=b[j])    ans+=a[i];
			a[i]=a[j]=0;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}

