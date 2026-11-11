#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
ll n;
string s="";
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c; 
		while(a--){
			s+=c;
		}
	}
	ll l=s.size();
	for(int i=0;i<(l+1)/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans<<'\n';
	return 0;
}

