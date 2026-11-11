#include<bits/stdc++.h>
using namespace std;
int ans=0;
void backtracking(vector<int>nums,int n,int m,int startIndex,int k,int res){
	if(k==m){
		ans=max(ans,res);
		return;
	}
//	if(res==0)return;
	for(int i=startIndex;i<=n+k-m+1;i++){
		bool flag=false;
		if(res==-1){
			res=nums[i];
			flag=true;
		}
		backtracking(nums,n,m,i+1,k+1,res&nums[i]);
		if(flag)res=-1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int>nums(n+2,0);
	for(int i=1;i<=n;i++)cin>>nums[i];
	backtracking(nums,n,m,1,0,-1);
	cout<<ans;
	
	return 0;
}