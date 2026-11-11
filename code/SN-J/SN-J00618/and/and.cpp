#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maxxx=INT_MIN;
vector<long long>a;
void dfs(long long dep,long long shu,long long And){
	if(shu>=m){
		maxxx=max(maxxx,And);
		return;
	}
	if(dep>n){
		return;
	}
	dfs(dep+1,shu+1,And&a[dep]);
	dfs(dep+1,shu,And);
	return;
}
bool deng(){	
	for(long long i=1;i<=n;i++){
		if(a[i]!=i-1){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	a.push_back(0);
	a.push_back(0);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a.push_back(0);
	}
	if(m==1){
		long long maxx=INT_MIN;
		for(long long i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}else if(m==2){
//		cout<<'S';
		long long maxx=INT_MIN;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(m==n){
		long long sum=INT_MAX;
		for(long long i=1;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}else if(m==(n-1)){
		long long sum=INT_MAX;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i!=j){
					sum&=a[i];
				}
			}
		}
		cout<<sum;
	}
	else if(deng()){	
		long long sum=INT_MAX;
		for(long long i=n;i>=n-m+1;i--){
			sum&=a[i];
		}
		cout<<sum;
	}
//	cout<<deng();
	else{
		dfs(1,0,INT_MAX);
		cout<<maxxx;
	}
	
	return 0;
}
