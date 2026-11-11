#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int c[500005];
int vis[500005];
int minnum=0x3f3f3f3f3f3f,maxnum=-0x3f3f3f3f3f3f;
bool check2(int y,int num){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		c[i]=y-a[i];
		if(c[i]<0) c[i]=0x3f3f3f3f3f3f3f;
	}
	int cnt=0;
	for(int i=1;i<=num;i++){
		int minx=0x3f3f3f3f3f3f;
		int lst=n+1;
		for(int j=1;j<=n;j++){
			if(vis[j]!=1&&c[j]<minx){
				vis[j]=1;
				vis[lst]=0;
				minx=c[j];
				lst=j;
			}
		}
		cnt+=minx;
	}
	return cnt<=m;
}
bool check(int x){//是否可以通过m次改变有x个相同水晶
	double l=minnum,r=maxnum,mid;
	for(int i=l;i<=r;i++){
		if(check2(i,x)) return true;
	}
	return false;
}
int erfen(int x,int y){//枚举相同水晶个数
	double l=x,r=y,mid;
	while(l<r){
		mid=ceil((l+r)/2);
		if(!check(mid)) r=mid-1;
		else l=mid;
	}
	return l;
}


signed main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minnum=min(minnum,a[i]);
		maxnum=max(maxnum,a[i]);
	}
	int ans=erfen(1,n);
	cout<<ans;
	return 0;
}