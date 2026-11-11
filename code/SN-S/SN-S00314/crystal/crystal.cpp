#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[323232],m,k[323232],sum[323232];
bool flag[323232];
struct Node{
	int x;
	pair<int,int>k;
}c[323232];
inline bool cmp(Node a,Node b){
	return a.x<b.x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<n;i++) if(abs(a[i]-a[i+1])>m) flag[i]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
//		c[i].x=abs(a[i]-a[i-1]);
//		c[i].k={i,i-1};
		sum[i]=sum[i-1]+a[i];
		for(int j=1;j<i;j++){
			if((sum[i]-sum[j]+m)/(i-j)>=a[i]) ans=i-j;
		}
//		for(int j=0;j<i;j++){
//			if((sum[i]-sum[j]+m)/(i-j)>=a[i]) ans=i-j;
//		}
//		if((sum[i]+m)/i>=a[i]) ans=i;
//		k[i]=abs(a[i]-a[i-1]);
//		k[i]-=k[i-1];
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=(sum[n]+m)/n) pos++;
	}
//	sort(c+1,c+1+n,cmp);
//	int l=0,r=0;
//	for(int i=1;i<=n;i++){
//		if(m<0) break;
//		if(l==0&&r==0) l=c[i].k.first,r=c[i].k.second,m-=c[i].x,ans++;
//		if(c[i].k.first==r) r=c[i].k.second,m-=c[i].x,ans++;
//		else if(c[i].k.second==l) l=c[i].k.first,m-=c[i].x,ans++;
//	}
//	cout<<"Cnter:";
//	for(int i=1;i<=n;i++){
//		cout<<k[i]<<' ';
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		m-=k[i];
//		if(m<0) break;
//		ans++;
//	}
	cout<<pos;
	return 0;
}
