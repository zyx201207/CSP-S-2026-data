#include <bits/stdc++.h>
using namespace std;
#define N 200000
int n,m,a[N+10],mx=0;
long long ans;
long long anss;
void cheat(){
	for(int i=0;i<=(1<<n)-1;++i){
		if(__builtin_popcount(i)!=m)continue;
		long long sum=(1<<n)-1;
		for(int j=0;j<n;++j){
			if((i>>j)&1)sum=sum&a[j+1];
		}
		ans=max(sum,ans);
	}
	cout<<ans;
	exit(0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i==1)anss=a[i];
		else anss=anss&a[i];
		mx=max(mx,a[i]);
	}
	if(n<=30){//AC
		cheat();
	}else if(m==n){
		cout<<anss;
	}else if(m==1){
		cout<<mx;
	}else if(m==2){//AC
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j)ans=max(ans,(long long)(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=m;++i){
			if(i==1)ans=a[i];
			else ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}

