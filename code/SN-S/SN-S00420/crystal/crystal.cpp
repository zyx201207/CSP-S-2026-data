#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long k=m;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<a[j-1]) swap(a[j-1],a[j]);
		}
	}
	for(int j=n;j>1;j--){
		for(int i=j;i>1;i--){
			if(m+a[i-1]>=a[i]){
				m-=(a[i]-a[i-1]);
				a[i-1]==a[i];
				sum[i]++;
			}else if(m<b[n]){
				cout<<'1';
				return 0;
			}
		}
		m=k;
	}

	long long q = sum[1];
	for(int i=1;i<=n;i++){
		if(sum[i]>q) q=sum[i];
	}
	cout<<q;
	return 0;
}
