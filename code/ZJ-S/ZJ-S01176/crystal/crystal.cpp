#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
int ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a_;
		cin >> a_;
		a.push_back(a_);
	}
	sort(a.begin(),a.end());
	
	int l=0,r=0;
	int sum=a[l];
	while(r<n){
		if(sum+m>=a[r]*(r-l+1)){
			ans=max(ans,r-l+1);
			r++;
			sum+=a[r];
		}
		else{
			sum-=a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}