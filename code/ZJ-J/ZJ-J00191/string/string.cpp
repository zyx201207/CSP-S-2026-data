#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+1;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	int n;
	cin>>n;
	int mx=0;
	ll sum=0;
	for(int i = 1;i<=n;i++){cin>>a[i]>>c[i];mx=max(mx,a[i]),sum+=a[i];}
	if(mx>500){
		while(1);
		return 0;
	}
	for(int i = 1;i<=n;i++) for(int j = 1;j<=a[i];j++) s+=c[i];
	ll l=s.size(),ans=0;
	s=" "+s;
	for(int i = 1;i<=l;i++){
		if(s[i]!=s[l-i+1]) s[i]=s[l-i+1],ans++;
	}
	cout<<ans;
	return 0;
}
