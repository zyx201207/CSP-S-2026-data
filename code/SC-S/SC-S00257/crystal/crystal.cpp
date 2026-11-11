#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int inf=-1;
long long a[N];
long long cha[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	ans=-1;
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	int sig=1;
	long long d=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d){
			sig=inf;
			break;	
		}
	}
	if(sig==1){
		long long me=m;
		int ans=1;
		while(1){
			if(me>=d){
				me-=d;
				ans++;
			}
			else{
				ans=min(ans,n);
				cout<<ans;
				return 0;
			}
			d=d+(a[2]-a[1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<':';
		for(int j=1;j<=n;j++)
		{
			cha[j]=a[i]-a[j];
			if(cha[j]<0)
				cha[j]=inf;
		}
		sort(cha+1,cha+n+1);
//		for(int j=1;j<=n;j++)
//		{
//			cout<<cha[j]<<' ';
//		}
//		cout<<'\n';
		long long me=m;
		int kl=0;
		for(int j=1;j<=n;j++)
		{
			if(cha[j]==-1) continue;
			if(me>=cha[j])
				me-=cha[j],kl++;
		}
		ans=max(kl,ans);
	}
	cout<<ans;
	return 0;
}
/*/
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7


5 3
1 2 3 4 5

/*/