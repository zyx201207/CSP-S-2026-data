#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,a;
string s;
string g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(int j=1;j<=a;j++){
			g+=s;
		}
	}
	for(int i=0;i<g.size()/2;i++){
		if(g[i]!=g[g.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
