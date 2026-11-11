#include <bits/stdc++.h>
freopen("migrate.in",r,stdin);
freopen("migrate.out",w,stdout);
using namespace std;

int n,c,t,d,mi,p,sum;
int a[1000];
long long x[2000200];
queue<int> q;
int bfs1(int l,int r,int y){

	int op=q.front();
	q.pop();
	l=op;
	while(x[l]-x[op]<=d&&l<=n){
		if(l>=r) return ++y;
		q.push(++l);
		
	}
	bfs1(l,r,++y);
}

void bg(){
	while(q.size())q.pop();
}

int bfs2(int l,int r,int y){
	if(y>r)return p;
	int op=q.front();
	q.pop();
	l=op;
	while(x[++l]-x[op]<=d&&l<=r){
		if(l==r&&y==mi)p++;
		q.push(l);
		
	}
	bfs2(l,r,++y);
	
}

int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		
		
		for(int i=1,j=i+1;i<n;i++){
		q.push(i);
		mi=bfs1(i,j,0);
		bg();
		q.push(i);
		int o=bfs2(i,j,1);
		if(o==2)sum++;
		}
		for(int i=1;i<=n;i++)x[i]=0;

		cout<<sum<<"\n";
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);


	return 0;
}