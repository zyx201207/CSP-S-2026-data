#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s.push_back(c);
		}
	}
	int l=s.size();
	for(int i=0,j=l;i<j;i++,j--){
		if(s[i]!=s[j])ans++;
	}cout<<ans;
	return 0;
} 
