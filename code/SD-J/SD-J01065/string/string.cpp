#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	for(int i=0,j=s.size()-1;i<s.size()&&j>=0;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans/2;
	return 0;
}
