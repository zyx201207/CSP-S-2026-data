#include<bits/stdc++.h>
using namespace std;
int a[100000005];
char c[26],b[26];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		sum+=a[i];
		for(int j=cnt;j<=cnt+a[i];j++)
		{
			b[j]=c[i];
		}
		cnt+=a[i];
	}
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		ans1=sum-max(a[i],a[i-1]);
	}
	int t=sum/2;
	for(int i=1;i<=sum/2;i++)
	{
		if(b[i]!=b[sum+1-i])
		{
			ans2++;
		}
	}
	cout << min(ans1,ans2);
	return 0;
}
