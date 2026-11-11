#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
char c;
string s;
signed main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=1;j<=m;j++)s+=c;
	}
	int g=s.size();
	for(int i=0,j=g-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
} 

