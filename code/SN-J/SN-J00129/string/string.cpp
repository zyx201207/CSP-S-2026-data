#include<bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		s.insert(s.size(),a,c);
	}
	l=s.size();
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
