#include <bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long> ,greater<long long> > pru;
priority_queue<long long,vector<long long>  > pre;
long long n,m;
long long a[500010],t[500010],pe[500010];

long long er1(long long l,long long r,long long mb){

	while(l<r){
		long long mid=(r-l+1)/2+l;
		if(pe[mb-1]-pe[mid-1]-t[mb]*(mb-mid)<=m){
			
			r=mid-1;
			
			
		}
		else{
			
			l=mid;
		
		}
	}
	long long mid=(r-l+1)/2+l;
	if(pe[mb-1]-pe[mid-1]-t[mb]*(mb-mid)<=m){
		l--;
	}
	else{
		
	}
			
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);   


	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		pru.push(a[i]);
		pre.push(a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		t[i]=a[n]-a[i];
	}
	for(long long i=1;i<=n;i++){
		pe[i]=pe[i-1]+t[i];
	}
	long long max_=1;
	for(long long i=2;i<=n;i++){
	
			
			max_=max(max_,i-er1(1,i-1,i));
	}
	cout<<max_;
	
	return 0;
} //Oct31==Dec25?
