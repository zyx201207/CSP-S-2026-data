#include<bits/stdc++.h>
using namespace std;
long long a[600006];
long long b[600006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n;
	cin>>m;
	int p = 0;
	int t = 0;
	int l = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			p = 1;
		}
	}
	t = a[1]-a[2];
	for(int i = 2;i<n;i++){
		if(a[i]-a[i+1]!=t){
			l = 1;
		}
	}
	long long k = 0;
	long long maxn = 0;
	if(!p){
		for(int i = 1;i<=n;i++){
			if((k+i)>m){
				cout<<i;
				return 0;
			}else{
				k = k+i;
			}
		}
		cout<<n;
		return 0;
	}else if(!l){
		if(a[1]>a[n]){
			for(int i = 1;k<=m;i++){
				if((k+i*t)>m){
					cout<<i;
					return 0;
				}else{
					k = k+i*t;
				}
			}
			cout<<n;
			return 0;
		}else{
			t = 0-t;
			for(int i = 1;i<=n;i++){
				if((k+i*t)>m){
					cout<<i;
					return 0;
				}else{
					k = k+i*t;
				}
			}
			cout<<n;
			return 0;
		}
	}else{
		sort(a+1,a+n+1);
		for(int i = 2;i<=n;i++){
			b[i] = a[i]-a[i-1];
		}
		for(int i = 1;i<=n;i++){
			bool q = 0;
			k = 0;
			for(long long j = 1;j<=n-i;j++){
				if(k+b[i+j]*j>m){
					maxn = max(maxn,j);
					q = 1;
					break;
				}else{
					k = k+b[i+j]*j;
				}
			}
			if(!q){
				maxn = max(maxn,n-i+1);
			}
		}
	}
	cout<<maxn;
}

