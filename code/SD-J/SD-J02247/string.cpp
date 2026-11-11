#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[200005];
char ch[200005];
int c1[20000005];///////////
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);/////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int o=0,t=0;	
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ch[i];
		t+=s[i];
		for(int j=t-s[i];j<=t;j++) c1[j]=ch[i]-'0';
	}
	int ii=1,nn=t,ans=0;
	while(ii<=nn){
		if(c1[ii]!=c1[nn]) ans++;////
		nn--;
		ii++;
	}
	cout<<ans;
	return 0;
} 
