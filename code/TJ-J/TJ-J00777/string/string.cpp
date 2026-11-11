#include<bits/stdc++.h>
using namespace std;
struct endq{
	int a;
	string b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<endq> nums;
	int cnt=0,n,temp;
	cin >> n;
	for (int i=0;i<n;i++){
		int t1;
		string t2;
		cin >> t1 >> t2;
		nums.push_back({t1,t2}); 
	} 
	while (nums.size()>1){
		temp=abs(nums[0].a-nums[n-1].a);
		if (nums[0].b!=nums[n-1].b) cnt += temp;
		if (nums[0].a>nums[n-1].a){
			nums[0].a=temp;
			nums.erase(nums.end()-1,nums.end());
		}else if (nums[0].a<nums[n-1].a){
			nums.erase(nums.begin(),nums.begin()+1);
			nums[n-1].a=temp;
		}else{
			if (nums[0].b==nums[n-1].b){
				nums.erase(nums.end()-1,nums.end());
				nums.erase(nums.begin(),nums.begin()+1);
			}else{
				nums.erase(nums.end()-1,nums.end());
				nums.erase(nums.begin(),nums.begin()+1);
				temp = nums[0].a;
			} 
		}
		
	}
	cout << cnt;
	return 0;
}

