#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+50;
long long n,m;
long long a[MAXN];
long long b[MAXN];

void check(){
	cout<<'\n';
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	cout<<'\n';
}

void readset(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}

void pre_readset(){
	freopen("crystal2.in","r",stdin);
}

void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}
}

void solve(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=a[i]+b[i-1];
	//check();
	
	long long maxn=1;
	for(long long i=1,j=1;j<n;){
		long long querysum=b[j+1]-b[i-1];
		long long nextsum=a[j+1]*(j-i+2);
		
		if(nextsum-querysum<=m)++j;
		else ++i;
		
		maxn=max(maxn,j-i+1);
	}
	
	cout<<maxn;
}

int main(){
	readset();
	//pre_readset();
	
	read();
	solve();
	return 0;
}