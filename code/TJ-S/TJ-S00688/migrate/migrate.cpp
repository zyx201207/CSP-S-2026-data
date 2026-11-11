#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &v, int d){
	int n = v.size();
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+2;j<n;j++){
			int cao;
			if(cao%3 == 0) ans++;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	for(int e=0;e<t;e++){
		int n,d;
		cin>>n>>d;
		vector<int> v(n);
		int last = 0;
		for(int i=0;i<n;i++) cin>>v[i];
		
		cout<<func(v, d)<<'\n';
	}
	
	
	return 0;
}
