#include<bits/stdc++.h>
using namespace std;

int n,m;
long long maxn=0;

struct node{
	long long b;
}a[200005];

long long f(int idx,int sum,long long an){
	if(idx>n&&sum!=m){
		return 0;
	}
	if(sum==m){
		return an;
	}
	for(int i=idx+1;i<=n;i++){
		long long d=an&a[i].b;
		maxn=max(maxn,f(i,sum+1,d));
	}
	return maxn;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i].b&a[j].b);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		maxn=4294967295;
		for(int i=1;i<=n;i++){
			maxn=maxn&a[i].b;
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		long long maxx=0;
		maxn=4294967295;
		for(int i=1;i<=n;i++){
			a[i].b=4294967295;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,maxn&a[i].b);
			}
		}
		cout<<maxx;
		return 0;
	}
	cout<<f(0,0,4294967295);
	return 0;
}
