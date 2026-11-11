#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int fa[1000000];
int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t!=0){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			fa[max(x,y)]=fa[min(x,y)];
		}
		t--;
	}
	return 0;
}
