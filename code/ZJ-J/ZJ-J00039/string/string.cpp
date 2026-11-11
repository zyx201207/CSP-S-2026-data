#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
char c[3456789];
ll ans=0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=0;
	for(int i=1;i<=n;i++){
		char xxx;
		int len;
		cin>>len;
		cin>>xxx;
		for(int j=l+1;j<=l+len;j++)c[j]=xxx;
		l=l+len;
	}
	
	int le;
	if(l&1)le=(l-1)/2;
	else le=l/2;
	for(int i=1;i<=le;i++){
		if(c[i]!=c[l-i+1])ans++;
	}
	cout<<ans;
	return 0;
} 
