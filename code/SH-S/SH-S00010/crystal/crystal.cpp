//crystal
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int nums[500005];
int sum[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >>n >>m;
	for (int i=1;i<=n;i++){
		cin >>nums[i];
	}
	sort(nums+1, nums+n+1);
	ll prev = nums[1];
	for (int i=2;i<=n;i++){
//		cout << nums[+i] << " " <<prev <<endl; 
		sum[i] = sum[i-1] + (i-1) *(nums[i] - prev);
		prev = nums[i];
//		cout <<sum[i] <<endl;
	}
//	cout <<endl;
	int prevs = 0;
	ll cnt = 0;
//	for(int i=1;i<=n;i++){
//		if (nums[i] == prevs){
//			cnt++;
//		}else{
//			cnt ++;
//			cout <<cnt << " " << nums[i] << endl; 
//			prevs = nums[i];
//			cnt = 0;
//		}
//	}
	int ans = 0;
	int l = 1;
	ll curr = nums[1];
	for (int i=1;i<=n;i++){
		curr = nums[i];
		while (l < n && ((sum[l] - sum[i-1] - (i-1) * (nums[l]-curr)) <=m)){
			l++;
//			cout << i <<" " << l <<endl;
//			cout << ((l-1) * (curr - nums[1])) <<endl;
		}
//		cout << l-i << endl;
		ans = max(ans, l-i);
		
	}
	cout <<ans <<endl;
}

