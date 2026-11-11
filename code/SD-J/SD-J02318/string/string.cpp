#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,cnt=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for (int i=1;i<=a;i++) s+=c;
	}
	for (int i=0;i<s.size()/2;i++){
		char t=s[s.size()-i-1];
		if(s[i]!=t) cnt++;
	}
	cout<<cnt;
	return 0;
}
