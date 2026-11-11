#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "/n";
using namespace std;
long long a[200005];
char b[200005];
char c[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n;
	cin>>n;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		f+=a[i]/2;
		for(int j=1;j<=a[i];j++)
		{
			c[j]=b[i];
		}
	}
	long long ans=0;
	for(int i=1;i<=f;i++)
	{
		if(c[i]!=c[2*f-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
