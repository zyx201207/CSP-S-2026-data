#include<bits/stdc++.h>
using namespace std;
int z(long long x){
	long long ans=0;
	long long i=1;
	while(x){
		long long v=x%2;
		x/=2;
		ans=ans+v*i;
		i*=10;		
	}
	return ans;
}
int check(long long x,long long y){
	long long ans=0;
	long long i=1;
	while(x && y){
		long long v=1;
		long long j=i-1;
		if(x%10==1 && y%10==1){
			while(j--){
				v=v*2;
			}
			ans+=v;
		}
		x/=10;y/=10;
		i++;
	}
	return ans;
}
long long y=0;
long long xy=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<long long> v(n);
	long long maxn=0;
	for(int i=0;i<n;i++){
		cin>>v[i];		
	}
	int m1=m-1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int k=j;
			while(m1--){
				long long x=v[i];
				long long y=v[k];
				k++;
				xy=check(z(x),z(y));
				if(y!=0){
					xy=check(z(y),z(xy));
				}else{
					y=xy;
				}
			}
			y=xy;
			maxn=max(maxn,y);
			m1=m-1;		
		}
	}
	cout<<maxn;
	return 0;
}