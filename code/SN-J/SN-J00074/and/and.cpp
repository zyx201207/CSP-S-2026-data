#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0;cin>>n>>m;
	vector<long long>nums;
	for(long long i=0;i<n;i++){
		long long num=0;cin>>num;
		nums.push_back(num);
	}
	sort(nums.begin(),nums.end(),cmp);
	long long ad=nums[0];
	for(long long i=1;i<m;i++){
		ad&=nums[i];
	}
	cout<<ad;
}
bool cmp(long long a,long long b){
	return a>b;
}
