#include <bits/stdc++.h>
using namespace std;
#define N 500000
#define int long long
int n,m,a[N+10];
bool A=1,B=1;
void cheatA(){
	int i=1;
	while(m>=0){
		m-=i;
		++i;
	}
	cout<<i-1;
	exit(0);
}
void cheatB(int d){
	int i=1,times=0;
	d=abs(d);
	while(m>=0&&i>0){
		m-=i;
		i+=d;
		++times;
	}
	cout<<times;
	exit(0);
}
void Sln_N_2(){
	int sum=0,ans=0;
	sort(a+1,a+n+1);
	for(int r=2;r<=n;++r){
		for(int l=1;l<=r;++l){
			sum=0;
			for(int k=l;k<=r;++k){
				sum+=a[r]-a[k];
			}
			if(sum>m)break;
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	exit(0); 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i)A=0;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])B=0;
		}
	}
	if(A){
		cheatA();
	}
	if(B){
		cheatB(a[n]-a[n-1]);
	}
	if(n<=500){
		Sln_N_2();
	}
	else if(n<=5000){
		int sum=0,ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			sum=0;
			for(int j=1;j<=i;++j){
				sum+=a[i]-a[j];
			}
			if(sum>m)break;
			ans=i;
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1); 
		while(m>=0){
			int mn=a[1],i=1;
			while(a[i]==mn&&m>=0){
				a[i]++;
				m--;
				i++;
			}
		}
		int mn=LLONG_MAX,place=1;
		for(int i=1;i<=n;++i){
			if(a[i]<=mn){
				mn=a[i];
				place=i;
			}
		}
		cout<<place;
	}
	return 0;
}

