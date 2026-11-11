#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
vector<int>e[maxn];
int read(){
	int x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=10*x+(c-'0');
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=0;j<=30;j++){
			if(x&(1<<j)){
				e[j].push_back(x);
			}
		}
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		if(e[i].size()>=m){
			ans|=(1<<i);
			for(int j=0;j<i;j++)e[j].clear();
			for(int j=0;j<e[i].size();j++){
				int v=e[i][j];
				for(int k=0;k<i;k++){
					if(v&(1<<k))e[k].push_back(v);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
