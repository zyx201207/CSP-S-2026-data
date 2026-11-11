#include<bits/stdc++.h>
using namespace std;

const int N=5e5+7;
int n;
long long m;
long long val[N];

bool check(int k){
	long long sum=0;
	for(int i=1;i<=k;i++){
		sum+=(val[k]-val[i]);
		if(sum>m)return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	sort(val+1,val+1+n);
	int l=1,r=n;
	int ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;	
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}