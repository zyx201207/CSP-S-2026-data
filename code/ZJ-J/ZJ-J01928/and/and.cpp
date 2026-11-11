#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],jh[200005],ans;
int f1[200005],f2[200005];
void dfs(int x,int s) {
	if(s<ans)return;
	if(x==m) {
		ans=max(ans,s);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(jh[i]==0) {
			jh[i]=1;
			dfs(x+1,s&a[i]);
			jh[i]=0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=20) {
		for(int i=1; i<=n; i++) {
			jh[i]=1;
			dfs(1,a[i]);
			jh[i]=0;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(m==1) {
		cout<<a[n]<<"\n";
		return 0;
	}
	if(m==n) {
		ans=a[1];
		for(int i=1; i<=n; i++)
			ans&=a[i];
		cout<<ans<<"\n";
		return 0;
	}
	if(m==2) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n-1) {
		f1[1]=a[1];
		for(int i=2; i<=n; i++)
			f1[i]=f1[i-1]&a[i];
		f2[n]=a[n];
		for(int i=n-1; i>=1; i--)
			f2[i]=f2[i+1]&a[i];
		ans=max(f1[n-1],f2[2]);
		for(int i=2; i<=n-1; i++)
			ans=max(ans,f1[i-1]&f2[i+1]);
		cout<<ans<<"\n";
		return 0;
	}
	int jjh=0;
	for(int i=1; i<=n; i++) {
		int x=1,jh=0;
		for(int j=0; j<=20; j++) {
			if(a[i]==x-1) {
				jh=1;
				break;
			}
			x*=2;
		}
		if(jh==0) {
			jjh=1;
			break;
		}
	}
	if(jjh==0) {
		cout<<a[n-m+1]<<"\n";
		return 0;
	}
	int x=1,jh=0;
	for(int j=0; j<=20; j++) {
		if(n==x) {
			jh=1;
			break;
		}
		x*=2;
	}
	if(jh==1) {
		jjh=0;
		for(int i=1; i<=n; i++)
			if(a[i]!=i-1) {
				jjh=1;
				break;
			}
		if(jjh==0) {
			ans=a[n];
			for(int i=n; i>=n-m+1; i--)
				ans&=a[i];
			cout<<ans<<"\n";
			return 0;
		}
	}
	jjh=0;
	for(int i=1; i<=n; i++)
		if(a[i]>=4) {
			jjh=1;
			break;
		}
	if(jjh==0) {
		int _1=0,_2=0,_3=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==1)_1++;
			if(a[i]==2)_2++;
			if(a[i]==3)_3++;
		}
		if(_3>=m) {
			cout<<3<<"\n";
			return 0;
		}
		if(_3+_2>=m) {
			cout<<2<<"\n";
			return 0;
		}
		if(_3+_1>=m) {
			cout<<1<<"\n";
			return 0;
		}
		cout<<0<<"\n";
		return 0;
	}
	ans=a[n];
	for(int i=n; i>=n-m+1; i--)
		ans&=a[i];
	cout<<ans<<"\n";
	return 0;
}