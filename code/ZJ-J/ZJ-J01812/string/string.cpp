#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	bool ok=1,cannotusestring=1;
	LL ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i!=1&&c[i]!=c[i-1]) ok=0;
		if(i!=1&&a[i]!=a[i-1]) cannotusestring=0;
	}
	if(ok){
		cout<<0;
		return 0;
	}
	if(cannotusestring){
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]) ans+=(LL)(a[i]); 
		}
		cout<<ans;
		return 0;
	}
	string s="";
	for(int i=1;i<=n;i++){
		while(a[i]--){
			s+=c[i];
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[n+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
