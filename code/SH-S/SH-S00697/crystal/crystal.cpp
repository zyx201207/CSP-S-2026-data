#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll nums[100000005],d[100000005];
int smallsum(int l,int r, auto a){
	ll small=0;
	for (int i=l+1;i<r+1;i++){
		small+=a[i];
	}
	return small;
}

int bigsum(int l,int r,auto a){
	ll big=0;
	for (int j=l;j<r;j++){
		big+=smallsum(j,r,a);
	}
	return big;
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n,m;
	cin>>n>>m;

	for (int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	sort(nums,nums+n);
	d[0]=nums[0];
	for (int i=1;i<n;i++){
		d[i]=nums[i]-nums[i-1];
	}
	
//	for (int i=0;i<n;i++) cout<<d[i]<<endl;
	
	ll maxans=1;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			ll times=bigsum(i,j,d);
//			cout<<times<<endl;
			if (times<=m){
				ll cnt=j+1-i;
				if (cnt>maxans) maxans=cnt;
			} 
		}
	}
	
	cout<<maxans;
	return 0;
}
