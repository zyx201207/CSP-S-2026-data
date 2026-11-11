#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int c;char ch;cin>>c>>ch;
		for(int j=1;j<=c;j++)s+=ch;
	}
	string ss=s;reverse(ss.begin(),ss.end());
	int ans=0;
	for(int i=0;i<(s.size()-1)/2;i++)ans+=(s[i]!=ss[i]);
	cout<<ans;
	return 0;
}

