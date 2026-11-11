#include<bits/stdc++.h>
using namespace std;
string s;
int n,a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s.push_back(c);
		}
	}
	int ans=0;
	for(int i=0;i<s.size()/2+1;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
