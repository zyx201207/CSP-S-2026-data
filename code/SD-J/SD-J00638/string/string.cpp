#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,len;
string s;
char c;
signed main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	cin>>n;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		len+=m;
		while(m--)s=s+c;
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1])ans++;
	}
	cout<<ans;
	return 0;
} 
