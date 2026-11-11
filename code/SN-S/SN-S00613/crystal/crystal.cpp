#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
int n,m,a[N],b[N],dp[N];//当在i时最大答案 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
//	int gou=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
/*	gou=a[2]-a[1];
	bool f=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=gou){
			f=1;
			break;
		}
	}
	if(!f){//deng cha shu lie 
		int c=m;
		int xc=gou;
		int iu=0;
		while (1)
		if(c-xc>=0 ) c-=xc,xc*=2,iu++;
		else{
			cout<<iu+1;
			return 0;
		}
	}*/
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++)//选到第几个
	int i=1; 
	while(1)
	{
//		cout<<endl;
		for(int j=1;j<=i;j++)//比他小到 
		{
			b[j]=a[i]-a[j];//差 
//		cout<<b[j]<<" ";
		}
		sort(b+1,b+1+i);
		int c=m;
		int z=1;
		while(z<=i)
		{
			if(c-b[z]>=0) c-=b[z++];
			else break;
		}
		dp[i]=z-1;
		int po=upper_bound(a+1,a+1+n,a[i])-a;//下一个坐标
		if(po>=n+1) break;
//	cout<<"**"<<i<<"}"<<po;
		for(int k=i;k<=po;k++) dp[k]=dp[i]+(k-i);
		i=po; 
	}
	int ans=0;
	for(int j=1;j<=n;j++) {
	//	cout<<dp[j]<<" ";
		ans=max(ans,dp[j]);
	}
	cout<<ans;
	return 0;
}/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9

*/
