#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> s1(200010);
int ans,a;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>a;
	for(int i=0;i<a;i++){
		int b=0;
		char c;
		cin>>b>>c;
		for(int j=0;j<b;j++){
			s1.push_back(c);
		}
	}
	
	int n = s1.size();
	for(int i=0;i<n/2+1;++i){
		if(s1[i] != s1[n-i-1]) ans++;
	}
	cout<<ans;
	
	return 0;
}


