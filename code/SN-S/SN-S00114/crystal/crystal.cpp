#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],h,maxn;
__int64 sum=0;
deque<long long> ddq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int z=1; z<=n; z++){
		cin>>a[z];
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int z=1; z<n; z++){
		c[z]=a[z+1]-a[z];
	}
	for(int z=1; z<n; z++){
		ddq.push_back(z);
		h+=c[z];
		sum+=c[z]*(ddq.size());
		//cerr<<sum<<" "<<h<<endl;
		while(sum>m){
			int o=ddq.front();
			ddq.pop_front();
			sum-=h;
			h-=c[o];
		}
		//cerr<<sum<<" "<<h<<endl<<endl;
		maxn=max(maxn,(long long)(ddq.size()));
	}
	cout<<maxn+1;
	return 0;
}
