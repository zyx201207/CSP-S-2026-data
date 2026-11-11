#include<bits\stdc++.h> 
using namespace std;
long long cnt=0;
long long num[200005];
char ch[200005];
long long h=0,t=0,nnn=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	t=n-1;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		nnn+=num[i];
		cin>>ch[i];
	}
	long long check=nnn%2;
	while(nnn!=check)
	{
		if(ch[h]!=ch[t])
		{
			nnn-=min(num[h],num[t])*2;
			cnt+=min(num[h],num[t]);
			long long ooo=min(num[h],num[t]);
			num[h]-=ooo;
			num[t]-=ooo;
		}
		else 
		{
			nnn-=min(num[h],num[t])*2;
			long long ooo=min(num[h],num[t]);
			num[h]-=ooo;
			num[t]-=ooo;
		}
		if(num[h]==0)
		{
			h++;
		}
		if(num[t]==0)
		{
			t--; 
		}
	}
	cout<<cnt;
	return 0;
}
