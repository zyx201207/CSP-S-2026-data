#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int id;
	char c;
}a[212345];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int L=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].c;
		L+=a[i].id;
		for(int j=1;j<=a[i].id;j++){
			s+=a[i].c;
		}
	}
	int ans=0;
	s='*'+s;
	for(int i=1;i<=L/2;i++){
		if(s[i]!=s[L+1-i]){
			ans++;
		}
	}
	cout<<ans;
}
//我常常追忆过去 
//坠机了 
/*
pan wang zhe pan wang zhe dong feng lai le chun tian de jiao bu jin le
*/
