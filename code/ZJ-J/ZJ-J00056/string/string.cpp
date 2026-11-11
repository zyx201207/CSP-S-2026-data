#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
long long n,cnt=0,sum=0;
char ch[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		int num;
		char ch1;
		cin>>num>>ch1;
		tmp+=num;
		for(int t=1+sum;t<=tmp;t++)
		{
			ch[t]=ch1;
		}
		sum+=num;
	}
	for(int i=1;i<=sum;i++)
	{
		if(i>=sum) break;
		if(ch[i]!=ch[sum]) cnt++;
		sum--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
