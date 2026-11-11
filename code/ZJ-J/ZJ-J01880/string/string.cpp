#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="0";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		string t;
		cin>>m;
		cin>>t;
		for(int i=1;i<=m;i++){
			s+=t;
		}
	}
	int m=s.size()-1;
	int ans=0;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
