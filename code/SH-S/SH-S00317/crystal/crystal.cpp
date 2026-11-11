#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long v[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	int l=0;
	for(int i=1,l=1;i<=n;++i){
		cin>>v[i];
		sort(v+1,v+1+n);
		sum+=(i-l)*(v[i]+v[i-l]);
		while(l<m){
			sum-=v[i]+v[l];
			++l;
		}
	}
	cout<<abs(sum);
	return 0;
}
