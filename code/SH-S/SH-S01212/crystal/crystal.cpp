#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> c(n);
	vector<long long> sum(n);
	
	
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c.begin(),c.end());
	sum[0]=c[0];
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+c[i];
	} 

	long long maxn=0;
	for(int i=1;i<n;i++){
		long long diff=c[i]*i-sum[i-1];
		if(diff>m) break;
		else maxn=i;
	}
	maxn++;
	
	cout<<maxn;
	
	
	
	return 0;
} 
