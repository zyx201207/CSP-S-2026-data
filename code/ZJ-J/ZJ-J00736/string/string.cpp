#include<bits/stdc++.h>
using namespace std;
string s;
int n,a;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;
		char b;
		cin>>b;
		for(int i=1;i<=a;i++)s+=b;
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans;	
	return 0;
}
