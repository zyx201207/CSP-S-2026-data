#include<bits/stdc++.h>
#pragma GCC optimize(2,3,"Ofast","inline")
using namespace std;
int c,n,m,d,q,w[505005];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
struct node{
	int e,v;
};
bool cmp(node i,node j){return i.v<j.v;}
vector<node>l[505000];
long long b[505050];
void dij(int x){
	queue<int>q;
	q.push(x);
	for(int i=1;i<=m+n;i++)b[i]=9999999999999;
	b[x]=0;
	while(q.size()){
		int f=q.front();
		//cout<<'x'<<f<<' '<<b[f]<<'x'<<endl;
		q.pop();
		for(auto i:l[f]){
			if(b[i.e]>b[f]+i.v){
				b[i.e]=b[f]+i.v;
				q.push(i.e);
			}
		}
	}
}
void write(long long x){
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main(){
  freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1,a,b;j<=k;j++){
			a=read();b=read();
			l[a].push_back({m+i,b});
			l[m+i].push_back({a,b});
		}
	}
	for(int i=1;i<=m+n;i++)sort(l[i].begin(),l[i].end(),cmp); 
	for(int i=1,x,y;i<=q;i++){
		x=read();y=read();
		dij(x);
		write(1LL*b[y]+w[x]+w[y]);
		putchar('\n');
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