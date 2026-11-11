#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		string y;
		cin>>x>>y;
		while(x--){
			s+=y;
		}
	}
	string ss;
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
	if(s==ss){
		cout<<"0";
		return 0;
	}
	int ans=0;
	string qs=s.substr(0,s.size()/2);
	string hs=s.substr(s.size()/2+1,s.size()-1);
	for(int i=0;i<s.size()/2;i++){
		if(qs[i]!=hs[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
