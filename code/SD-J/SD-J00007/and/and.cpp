#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define se second
#define fi first
using namespace std;
const int N=2e5+5;
ll n,m,a[N],s[40][N],sk[N],li[N],tong[N],sum;
ll t=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		li[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll po=a[i],x=0;
		while(po)
		{
			if(po%2==1)s[x][sk[x]++]=i;
			x++;
			po/=2;
		}
		t=max(t,x);
	}
//	for(int i=0;i<t;i++){
//		for(int j=0;j<sk[i];j++){
//			cout<<s[i][j];
//		}
//		cout<<endl;
//	}
	// 统计二进制 <-
	ll di=0;
	for(int i=t-1;i>=0;i--){
		if(sk[i]>=m) {
			di=i;
			for(int j=0;j<sk[i];j++)
			{
				tong[s[i][j]]=1;
			}
			sum+=pow(2,i);
			break;
		}
	}
//	cout<<di<<sum;
	for(int i=di-1;i>=0;i--){
		ll tong2[N]={},xian=0;
		for(int j=0;j<sk[i];j++)
		{
			if(tong[s[i][j]]){
				tong2[s[i][j]]=1;
				xian++;
			}
		}
//		cout<<i;
		for(int j=0;j<200009;j++) {
			tong[j]=tong2[j];
		}
		if(xian<m) break;
		sum+=pow(2,i);
	}
	cout<<sum;
	
	return 0; 
}
	
