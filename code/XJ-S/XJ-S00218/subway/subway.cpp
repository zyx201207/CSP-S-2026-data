#include <iostream>
#include <vector>
#include <queue>

#define _ll long long
using namespace std;

struct node{
	char sx;//shuxing m stat l line
	bool flag;
	vector<int> access;
	vector<int> dist;
};
inline _ll read(){
	short f=1;long long ret=0;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch-48);
		ch=getchar();
	}
	return ret*f;
}
int ts[500050];

node station[500800];
int l[500050];
int r[500050];
int c,n,m,d,q;
void clear(){
	for(int i=1;i<=n;i++){
		station[500050+i].flag=0;
	}for(int i=1;i<=m;i++){
		station[i].flag=0;
	}
}
struct pir{
	int i,t;
};
int bfs(int s,int e){
	int f=1e9;
	station[s].flag=1;
	queue<pir> a;
	a.push({s,0});
	while(!a.empty()){
		if(a.front().i==e)f=min(f,a.front().t);
		int lng=station[a.front().i].access.size();
		for(int i=0;i<lng;i++){
			if(station[station[a.front().i].access[i]].flag==0);
			a.push({station[a.front().i].access[i],a.front().t+station[a.front().i].dist[i]});
		}
		a.pop();
	}
	return f;
}
int main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		ts[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;i++){
			station[500050+j].access.push_back(read());
			station[500050+j].dist.push_back(read());
		}
	}
	for(int i=1;i<=q;i++){
		l[i]=read();
		r[i]=read();
		cout<<bfs(l[i],r[i])<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
	Name: Void==GM_Returned_True
	Copyright: oiqingeryijuahuaile*2
	Author: NoTimeOierNotyisang
	Date: 31/10/26 17:42
	Deflybrokenswingscription:
*///  [=======] [===]
/*yuanjihua:
srand(799325^c);
	for(int i=1;i<=q;i++){
		cin>>t;
		cin>>t;
		cout<<rand()<<endl;
	}
*/
/*
BFS notime did not finished          \\  //   9961
freopen("crystal.in","r",stdin);      \\//  perfect good bad miss
	freopen("crystal2.out","w",stdout);\/     1145  14    0  0
*/
