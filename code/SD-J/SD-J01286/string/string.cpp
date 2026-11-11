#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,cn;
string s;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		cin>>x>>c;
		while(x--)s.push_back(c);
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])cn++;
	}
	cout<<cn;
	return 0;
}
