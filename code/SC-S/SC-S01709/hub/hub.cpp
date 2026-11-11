#include <bits/stdc++.h>
freopen("hub.in",r,stdin);
freopen("hub.out",w,stdout);
using namespace std;





int c,t,n,k;
int a[4020],b[4020],u[4100];
queue<int> c[4100];
queue<int> q;
int bfs(int l,int r,int y){
	while(c[l].size()){
		q.push(c[l].front());
		if(c.size()==0)return 0;
		if(q.front()==r){
		return ++y;
		}
		c[l].pop();
	}
	int op=q.front();
	q.pop();
	bfs1(o,r,++y);
}int ma;
int main(){
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i]>>b[i];
			c[i].push(j);
			c[j].push(i);
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<n;++){
			u[i]=bfs(i,j,0);
		
		}}
		
		sort(u+1,u+n);
		int ma=0;
		for(int i=1;i<=k;i++){
			ma=max(ma,u[i]);
		}
		cout<<ma;
		
	}
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}