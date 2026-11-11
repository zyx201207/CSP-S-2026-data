#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	int le=(s.size()+1)/2,ans=0;
	for(int i=0;i<le;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
