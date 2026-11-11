#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long ans=0,t;
vector<long long> x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		x.push_back(t);
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(long long j:x){
			if(j&(1LL<<i)) cnt++;
		}
		if(cnt>=m){
			for(long long j:x){
				if(j&(1LL<<i)) y.push_back(j);
			}
			x=y;
			y.clear();
			ans+=(1LL<<i);
		}
	}
	cout<<ans;
	return 0;
}
