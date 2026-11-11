#include<iostream>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int dp[N];
int lst[N],nxt[N];
int pos[M];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		nxt[pos[a[i]]]=i;
		lst[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	//for(int i=1;i<=n;i++) cout<<lst[i]<<" "<<nxt[i]<<endl;
	int k,r;
	for(int i=1;i<=n;i++)
	{
		k=nxt[i],r=0;
		if(k==0) k=n+1;
		for(int j=i+1;j<k;j++)
		{
			if(lst[j]>i) continue;
			if(lst[j]>r) 
			{
				dp[i]+=lst[j]-dp[lst[j]];
			}
			r=max(r,lst[j]);
			//cout<<r<<" ";
		}
	}
	for(int i=1;i<=m;i++) cout<<pos[i]-dp[pos[i]]<<" ";
	return 0;
}
