//李铭宸 西安交通大学附属中学 SN-J00830
#include <bits/stdc++.h>
using namespace std;
char a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	int top=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int cnt;
		char c;
		cin>>cnt>>c;
		sum+=cnt;
		for(int j=1;j<=cnt;j++)
		{
			a[top++]=c;
		}
	}
	int len=sum;
	if(sum%2==1) sum--;
	int ans=0;
	for(int i=1;i<=sum/2;i++)
	{
		if(a[i]!=a[len-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
