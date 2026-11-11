#include<bits/stdc++.h>
using namespace std;
long long n,x,L,ans=0,m;
string s;
char sx;
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>sx;
		for(long long i=1;i<=x;i++)s+=sx;
		L+=x;
	}
	m=L-1;
	for(long long i=1;i*2<=L+1;i++){
		if(s[i-1]!=s[m-i+1])ans++;
	}
	cout<<ans;
	return 0;
}