#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int ans,n,k;
int a[N];
void handle_ab(){
	int diff=abs(a[1]-a[2]);
	int num=0;
	int mxv=0;
	for(int i=1;i<=N;++i){
		num+=i*diff;
		if(num>k){
			mxv=i;
			break;
		}
	}
	cout<<min(mxv,n)<<endl;
//	if(n<mxv){
//		cout<<v[n]+1;
//	}else{
//		cout<<mxv+1;
//	}
	return;
}
int check(int to){
	int m=k;
	vector<int>nums;
	for(int i=1;i<=n;++i){
		if(a[i]<=to){
			nums.push_back(to-a[i]);
		}else{
			break;
		}
	}
	sort(nums.begin(),nums.end());
	int ret=0;
	for(int i=0;i<nums.size();++i){
		if(nums[i]>m){
			break;
		}
		m-=nums[i];
		ret++;
	}
	return ret;
}
signed main(){
	//70pts
	//todo : optimize farther(not look at each a[i])
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	bool ab=true;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i>=3&&abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])){
			ab=false;
		}
	}
	if(ab){
		handle_ab();
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		ans=max(ans,check(a[i]));
	}
	cout<<ans;
	return 0;
}
/*
7
10
2 4 6 8 10 12 14
*/