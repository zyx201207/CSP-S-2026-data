#include<bits/stdc++.h>
using namespace std;
long long a[35]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long b[200010];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n,ans;
	cin>>n;
	int m;
	cin>>m>>ans;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<30;j++)
		{
			if(b[i]<a[j]-1)
			{
				continue;
			}
			else if(b[i]==a[j]-1)
			{
				long long cc=b[i];
				cc&=b[m];
				cout<<cc;
				return 0;
			}
		}
	}
	return 0;
} 
