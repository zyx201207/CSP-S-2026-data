#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	vector<long long> vec(n+1,0);
	vector<long long> chafen(n+1,0);
	vector<long long> yaotian(n+1,0);
	for(long long i=1;i<=n;i++){
		cin>>vec[i];
	}
	
	sort(vec.begin()+1,vec.end());
	
	for(long long i=1;i<=n;i++){
		chafen[i]=vec[i]-vec[i-1];
	}
	
	yaotian[1]=0;
	for(long long i=2;i<=n;i++){
		yaotian[i] = yaotian[i-1] + (i-1) * chafen[i];
	}
	
	long long ans=1;
	for(long long i=1;i<=n;i++){
		
		long long last=i;
		long long first;
		
		long long l=1,r=last;
		while(l<=r){
			long long mid=(l+r)/2;
			if( yaotian[last] - yaotian[mid] - ((mid-1)*(vec[last]-vec[mid])) <= m ){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		first=l;
		
		ans=max(ans,last-first+1);
		
	}
	
	cout<<ans;
	
	return 0;
}
