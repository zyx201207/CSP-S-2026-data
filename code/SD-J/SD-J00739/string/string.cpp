#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=2e5+10;
ll n,a[N],ans=0;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	ll len=s.size();
	s=" "+s;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) ans++;
	} 
	cout<<ans;
	
	return 0;
}
