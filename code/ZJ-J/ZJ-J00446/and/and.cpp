#include <bits/stdc++.h>
using namespace std;
long long n,m,t[45],a[200010],ans=0,maxn,sum,minn,bz=1;
bool cmp(long long x,long long y){
	return x>y;
}
void initbz(){
	long long t=2;
	for (int i=2;i<=31;++i){
		bz+=t;
		t*=t;
	}
}
//bool num[200010][45];
long long ayy(long long x,long long y){
	long long tx=x,ty=y,ans=0,t=1;
	while (tx && ty){
		long long t1=tx%2,t2=ty%2;
		if (t1==1&&t2==1){
			ans+=t;
		}
		t*=2;
		tx/=2;
		ty/=2;
	}
	return ans;
}
/*
void solve(int x,int p){
	int tx=x,cnt=0;
	while (tx){
		cnt++;
		num[p][cnt]=tx%2;
		tx/=2;
	}
}*/
void dfs(long long p,long long v,long long usenum){
	if (p>n||usenum>m){
		return;
	}
	if (v==0&&usenum>0){
		return;
	}
	if (v==0&&usenum==0){
		dfs(p+1,a[p],1);
		dfs(p+1,0,0);
		return;
	}
	if (usenum==m){
		ans=max(ans,v);
		return;
	}
	if (p==n){
		if (usenum==m-1){
			ans=max(ans,ayy(a[p],v));
		}
		return;
	}
	int nv=ayy(a[p],v);
	dfs(p+1,nv,usenum+1);
	if (n-p+usenum>=m){
		dfs(p+1,v,usenum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	initbz();
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (i==1){
			sum=a[i];
		}else {
			sum=ayy(sum,a[i]);
		}
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if (n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}else if (n==m){
		cout<<sum;
		return 0;
	}else if (n==1){
		cout<<maxn;
		return 0;
	}else if (m==n-1){
		bool flag=true;
		if (a[1]==minn){
			flag=false;
			ans=a[2];
			for (int i=3;i<=n;++i){
				ans=ayy(ans,a[i]);
			}
		}else {
			ans=a[1];
			for (int i=2;i<=n;++i){
				if (a[i]==minn&&flag){
					flag=false;
					continue;
				}
				ans=ayy(ans,a[i]);
			}
		}
		cout<<ans;
		return 0;
	}else if (m==2){
		for (int i=1;i<=n;++i){
			for (int j=1;j<i;++j){
				ans=max(ans,ayy(a[i],a[j]));
			}
		}
		cout<<ans;
		return 0;
	}else{
		if (ayy(a[1],bz)==a[1]&&ayy(a[2],bz)==a[2]){
			sort(a+1,a+n+1,cmp);
			cout<<a[m];
		}else {
			dfs(1,0,0);
			cout<<ans;
		}
	}
	return 0;
}