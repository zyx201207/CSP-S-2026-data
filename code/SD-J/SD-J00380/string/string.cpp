#include<bits/stdc++.h>
using namespace std;
int n; 
string s;
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0); 
	s+=' ';
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	for(int i=1;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

