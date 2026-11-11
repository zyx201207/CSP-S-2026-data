#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,m,d,c,q,cnt,cur;
bool vis[1000001];
long long t[1000001],dis[1000001];
vector<int>v[1000001];
vector<long long>w[1000001];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >pq;
struct ques{
	int x,y,id;
	long long ans;
}op[100001];
long long read(){
	long long ret=0,sgn=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		sgn=-1; 
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret*=10;
		ret+=c-48;
		c=getchar();
	}
	return ret*sgn;
}
bool cmp1(ques al,ques bt){
	return al.x<bt.x;
}
bool cmp2(ques al,ques bt){
	return al.id<bt.id;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); 
	n=read(); 
	m=read(); 
	d=read(); 
	q=read(); 
	for(int i=1;i<=m;i++){
		t[i]=read();
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		cnt++;
		for(int j=1;j<=k;j++){
			int x;
			long long tim;
			x=read();
			tim=read();
			v[x].push_back(cnt);
			w[x].push_back(tim);
			v[cnt].push_back(x);
			w[cnt].push_back(tim);
		}
	}
	for(int i=1;i<=q;i++){
		op[i].x=read();
		op[i].y=read();
		op[i].id=i;
	}
	sort(op+1,op+1+q,cmp1);
	for(int i=1;i<=q;i++){
		if(op[i].x!=cur){
			for(int j=1;j<=cnt;j++){
				dis[j]=10000000000000000ll;
				vis[j]=0;
			}
			dis[op[i].x]=0;
			pq.push({0,op[i].x});
			while(!pq.empty()){
				pair<long long,long long>c=pq.top();
				pq.pop();
				if(vis[c.second])continue;
				vis[c.second]=1;
				for(int i=0;i<(int)v[c.second].size();i++){
					if(dis[c.second]+w[c.second][i]<dis[v[c.second][i]]){
						dis[v[c.second][i]]=dis[c.second]+w[c.second][i];
						pq.push({dis[c.second]+w[c.second][i],v[c.second][i]});
					}
				}
			} 
			cur=op[i].x;
		}
		op[i].ans=dis[op[i].y]+t[op[i].x]+t[op[i].y];
	}
	sort(op+1,op+1+q,cmp2);
	for(int i=1;i<=q;i++){
		printf("%lld\n",op[i].ans);
	}
	return 0;
}
