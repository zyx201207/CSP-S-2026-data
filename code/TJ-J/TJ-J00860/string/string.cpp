#include<bits/stdc++.h>
#include<cstring>
using namespace std;
long long ans=0,n,d[30]={};
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	char c;
	for(int i=1,a;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s.push_back(c);
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++; 
	}
	printf("%lld",ans);
	return 0;
}
