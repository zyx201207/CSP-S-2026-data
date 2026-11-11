#include <bits/stdc++.h>
using namespace std;
int c,t,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>u>>v;
		bool a[u+1][u+1]={0},gl[u+1]={0};
		for(int i=0;i<u;i++){
			int x,y;
			cin>>x>>y;
			a[x][gl[x]+1]=y;
			a[y][gl[y]+1]=x;
			gl[x]++;
			gl[y]++;
		}
		
	}
	return 0;
}
