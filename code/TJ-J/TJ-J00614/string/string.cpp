#include<bits/stdc++.h>
using namespace std;
long long T,len,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		int n;
		string c;
		cin>>n>>c;
		for(int i=0;i<n;i++) s+=c;
	}
	len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}

