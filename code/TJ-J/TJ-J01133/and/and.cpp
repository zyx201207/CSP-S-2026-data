#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<long long> nums;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		nums.push_back(a);
	}
	long long maxn=-1;
	long long result=1;
	if(m==1){
		for(int i=0; i<n; i++){
			maxn=max(maxn, nums[i]);
		}
		cout << maxn;
		return 0;
	}else if(m==n){
		for(int i=0; i<n; i++){
			result=result&nums[i];
		}
		cout << result;
		return 0;
	}else if(m==2){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i!=j) maxn=max(maxn, nums[i]&nums[j]);
			}
		}
		cout << maxn;
		return 0;
	}
	
	return 0;
}
