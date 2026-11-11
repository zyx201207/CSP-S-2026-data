#include<bits/stdc++.h>
#define ll long long
const short N = 510;
const int M = 500010;
using namespace std;
template<class T>
inline void read(T &sum){
	int c = sum = 0;bool y = 1;
	while(c!='-'&&(c<'0'||c>'9'))if(c==EOF)return;else c=getchar();
	if(c=='-')y=0,c=getchar();
	while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+c-'0',c=getchar();
	sum=y?sum:-sum;
}
struct node{
	int to;
	ll ti;
};
int l[M];
inline int find(int x){
	return l[x]==x?x:l[x]=find(l[x]);
}
short n,d;
int m,q,f[M];
ll w[N],t[M],t1,dis[M];
vector<node> p[M];
inline void dfs(){
	
}
int main(){
	int k,x,y;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(d),read(n),read(m),read(d),read(q);
	for(int i = 1; i <= m; i++) read(w[i]),l[i]=i;
	for(short i = 1; i <= n; i++){
		read(k);read(x),read(t[x]);
		for(int j = 2; j <= k; j++)
			read(y),read(t1),
			f[y]=x,l[y]=x,
			p[x].push_back((node){y,t[x]+t1}),
			p[y].push_back((node){x,t[x]+t1});
	}
	///dijs(); 
	for(int i = 1; i <= q; i++){
		read(x),read(y);
		if(f[x]==f[y]){
			d=t1=0;
			for(auto j:p[f[x]]){
				if(j.to==x)t1=j.ti-t[x];
				if(j.to==y)d=j.ti-t[x];
				if(t&&t1){
					cout << t1+d+w[x]+w[y] << endl;
					break;
				}
			}
		}
		else if(f[x]==y){
			d = 0;
			for(auto j:p[y])
				if(j.to==x){
					cout << j.ti+w[x]+w[y] << endl;
					break;
				}
		}
		else if(f[y]==x){
			d = 0;
			for(auto j:p[x])
				if(j.to==y){
					cout << j.ti+w[x]+w[y] << endl;
					break;
				}
		}else{
			
		}
	}
	return 0;
}
