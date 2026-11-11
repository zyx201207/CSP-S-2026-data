#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,ans;
string s;
vector<char>g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	g.push_back('0');
	for(int i=1;i<=n;i++){
		int op;
		char x;
		cin>>op>>x;
		while(op--){
			g.push_back(x);
		}
	}
	n=g.size()-1;
	for(int i=1;i<=n/2;i++){
		if(g[i]!=g[n+1-i])ans++;
		// cout<<g[i]<<" ";
	}
	cout<<ans;
	return 0;
}