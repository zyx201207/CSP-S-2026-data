//钟林希 西安翱翔中学 SN-J00675 
#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans,num;
struct asa
{
	int vi;
	char c;
}a[200050];
char find(long long x)
{
	int cnt=0;
	while(x>0)
	{
		cnt++;
		x-=a[cnt].vi;
	}
	return a[cnt].c;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int s;
		char y;
		cin>>s;
		cin>>y;
		a[i].vi=s;
		a[i].c=y;
		sum+=s;
	}
	num=(sum+1)/2;
	for(long long i=1;i<=num;i++)if(find(i)!=find(sum+1-i))ans++;
	cout<<ans;
	return 0;
}
