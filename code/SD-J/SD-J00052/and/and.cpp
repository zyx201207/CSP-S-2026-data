#include <bits/stdc++.h>
using namespace std;
int main(){
	
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >>n >> m;
	vector <long long> nums;
	for (long long i =0;i<n;i++){
		long long linshi;
		cin >> linshi;
		nums.push_back(linshi);
	}
	
	long long  maxh = 0;
	if (m==1){
		sort(nums.begin(),nums.end());
		maxh = nums[nums.size()-1];
	}else{
		if (m==2){
			for(long long i =0;i<n;i++){
				 
				for(long long j =0;j<n;j++){
					
					if (i!=j){
						if(nums[i]&&nums[j]>maxh){
							maxh=nums[i]&&nums[j];
						}
					}
				}
			}
		}
	}cout << maxh;
	return 0;
}
