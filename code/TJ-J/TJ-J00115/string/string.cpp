#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll>
#define fi first
#define se second 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,a;
	string s;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	string s2=s;
	reverse(s.begin(),s.end());    
	ll sum=0;
	if(s2==s)cout<<0;  
	else{
		for(int i=0;i<s.length();i++){
			if(s[i]!=s2[i])sum++;
		}
		cout<<sum/2;
	}
	return 0;
} 
