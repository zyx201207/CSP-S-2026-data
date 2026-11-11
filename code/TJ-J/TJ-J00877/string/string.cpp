#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=(s.size()+1)/2;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
