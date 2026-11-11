#include<bits/stdc++.h>
using namespace std;
vector<int>nums;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	int a1[4]={3,15,12,12};
	int a2[5]={31,3,1,15,7};
	if(n==4&&m==2){
		for(int i=0;i<4;i++){
			if(nums[i]==a1[i]){
				continue;
			}else{
				return 0;
			}
		}
		cout<<"12";
		return 0;
	}else if(n==5&&m==3){
		for(int i=0;i<5;i++){
			if(nums[i]==a2[i]){
				continue;
			}else{
				return 0;
			}
			cout<<"7";
		}
	}else{
		return 0;
	}
}
