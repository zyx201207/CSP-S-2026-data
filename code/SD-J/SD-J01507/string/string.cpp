#include<bits/stdc++.h>
using namespace std;
string s;
char a;
long long n,b,ans,num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>b>>a;
		while(b--)s+=a;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
	return 0;
} 
