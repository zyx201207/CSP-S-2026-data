#include<bits/stdc++.h>
using namespace std;
int c,xx,yy,n,m,d,qqq,w[500010],k[5100],a[510][500010],t[510][500010],z1[500010],top[510010];
bool f[510010];
int ans[510010];
struct st{
	int u,v,x;
}tree[51010][30];
int hash_state(int y,int z){
	return (y+1)*m+z;
}
void build(){
	for(int i=1;i<=m;i++){
		top[i]++;//地铁口到站厅 
		tree[i][top[i]].u=i;
		tree[i][top[i]].v=m+i;
		tree[i][top[i]].x=w[i];
		top[m+i]++;//站厅到地铁口 
		tree[m+i][top[m+i]].u=m+i;
		tree[m+i][top[m+i]].v=i;
		tree[m+i][top[m+i]].x=w[i];
	}
}
void add(int i,int y,int z){
//	cout<<i<<' '<<y<<' '<<z<<endl;
	top[i]++;
	tree[i][top[i]].u=i;
	tree[i][top[i]].v=y;
	tree[i][top[i]].x=z;
	top[y]++;
	tree[y][top[y]].u=y;
	tree[y][top[y]].v=i;
	tree[y][top[y]].x=z;
	return ;
}
int dj(){
	priority_queue<int,vector<int>,greater<int> >q;
	q.push(xx);
	memset(f,0,sizeof(f));
	memset(ans,0x3f,sizeof(ans));
	ans[xx]=0;
	while(q.size()){
		int x1=q.top();
		q.pop();
		if(f[x1]){
			continue;
		}
		f[x1]=1;
		for(int i=1;i<=top[x1];i++){
			int y=tree[x1][i].v;
			int z=tree[x1][i].x;
//			cout<<x1<<' '<<i<<' '<<y<<' '<<z<<endl;
			if(ans[y]>ans[x1]+z){
				ans[y]=ans[x1]+z;
//				cout<<y<<' '<<ans[y]<<endl;
				q.push(y);
			}
		}
	}
	return ans[yy];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qqq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	build();
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];	
			z1[a[i][j]]++;
//			cout<<a[i][j]<<endl; 
			add(m+a[i][j],hash_state(i,a[i][j]),t[i][j]);
			for(int l=1;l<j;l++){
				add(hash_state(i,a[i][l]),hash_state(i,a[i][j]),0);
			}
		}
	}
//	cout<<top[6]<<endl;
	while(qqq--){
		cin>>xx>>yy;
		cout<<dj()<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
