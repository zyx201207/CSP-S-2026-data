#include<bits/stdc++.h>
#define ll long long
using namespace std;
//3(WA   40
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	unsigned ll m;
	cin>>n>>m;
	vector<ll> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(),v.end());
	
	vector<ll> cha(n,0);
	cha.push_back(0);
	for(int i=n-2;i>=0;i--){
		cha[i] = v[i+1] - v[i] + cha[i+1];
	}
	
	unsigned ll sum = 0;
	for(int i=0;i<n;i++){
		sum += cha[i];
	}
	
	vector<int> ans;
	
	for(int i=n-1;i>=0;i--){
		sum -= (cha[i] - cha[i+1]) * (i+1);
		
		if(sum <= m){
			ans.push_back(i+1);
		}
		
		unsigned ll back = 0;
		for(int j=0;j<i;j++){
			sum -= cha[j];
			back += cha[j];
			if(sum <= m){
				ans.push_back(i-j);
			}
		}
		sum += back;
	}
	
	cout<<*max_element(ans.begin(),ans.end());
	
	return 0;
}
