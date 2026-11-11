#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a,s,ans;
vector <int> g;
vector <int> p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		g.push_back(a);
	} 
	for(int i=30;i>=0;i--){
		s=0;
		int f=1<<i;
		int sz=g.size();
		for(int j=0;j<sz;j++){
			if(g[j]&f){
				s++;
				p.push_back(g[j]);
			}
		}
		if(s>=m){
			ans+=1<<i;
			g.clear();
			sz=s;
			for(int j=0;j<s;j++){
				g.push_back(p[j]);
			}
		}
		p.clear();
	}
	cout<<ans;
	return 0;
} 
