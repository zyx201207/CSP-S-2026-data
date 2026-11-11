#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
class node{
	public:
		int num,val;
		bool operator< (const node& d) const{
			return val>d.val;
		}
};
long long c,n,m,d,q,w[500005],k[505],A,T,dis[200005],x[100005],y[100005];
vector<long long> v[200005],va[200005];
node nd,f;
priority_queue<node> pq;
long long dij(long long fir,long long lst){
	nd.num=fir;nd.val=0;
	pq.push(nd);
	while(!pq.empty()){
//		cout<<"Q";
		f=pq.top();
		pq.pop();
		if(f.val>dis[f.num]){
			continue;
		}
		for(int i=0;i<v[f.num].size();i++){
			if(f.val+va[f.num][i]<dis[v[f.num][i]]){
				dis[v[f.num][i]]=f.val+va[f.num][i];
				nd.num=v[f.num][i];
				nd.val=dis[v[f.num][i]];
				pq.push(nd);
			}
		}
	}
//	cout<<"P";
	return dis[lst];
}
int main(){
//	freopen("subway4.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout<<"Q";
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			A=read();T=read();
			v[A].push_back(m+i);
			v[m+i].push_back(A);
			va[A].push_back(T);
			va[m+i].push_back(T);
		}
	}
	for(int i=1;i<=q;i++){
		x[i]=read();y[i]=read();
		for(int j=1;j<=n+m+1;j++){
			dis[j]=1e18;
		}
		cout<<dij(x[i],y[i])+w[x[i]]+w[y[i]]<<endl;
	}
	return 0;
}
//2e5->1e5+500
//don't forget add (w[x]+w[y])