#include<bits/stdc++.h>
using namespace std;
long long a[510000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxn=1e9;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
	}
	else if(n==m){
		long long cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	else if(m==2){
		long long maxn=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	return 0;
}
