#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
inline void read(long long& x){
	x=0;
	int c=gc();
	bool f=0;
	while(!isdigit(c))(c=='-')&&(f=1),c=gc();
	while(isdigit(c))x=(x<<3)+(x<<1)+c-48,c=gc();
	return (f==1)&&(x=-x),void();
}
void write(long long x){
	if(x<0)pc('-'),x=-x;
	if(x<10)return pc(x+48),void();
	write(x/10);
	return pc(x%10+48),void();
}
long long n,m;
long long dd;
vector<pair<int,long long>>v[505];
vector<pair<int,long long>>v1[500005];
long long d[505][505];
long long b[505][505];
long long lx[505][505];
long long a[500005];
long long q;
void dj(int st){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
	while(q.size())q.pop();
	q.push({0,st});
	d[st][st]=0;
	while(q.size()){
		long long w=q.top().first,p=q.top().second;
		q.pop();
		if(b[st][p]==1)continue;
		b[st][p]=1;
		for(auto i:v[p]){
			long long np=i.first,ww=i.second;
			if(b[st][np]==1)continue;
			if(w+ww<d[st][np]){
				d[st][np]=w+ww;
				q.push({d[st][np],np});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c;
	read(c);
	read(n);read(m);read(dd);read(q);
	for(int i=1;i<=m;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=1000000000000000005ll;
			lx[i][j]=1000000000000000005ll;
		}
	}
	for(int i=1;i<=n;i++){
		long long k;
		read(k);
		for(int j=1;j<=k;j++){
			long long x,t;
			read(x);read(t);
			for(auto ii:v1[x]){
				int np=ii.first;
				long long w=ii.second;
				lx[np][i]=min(lx[np][i],t+w);
				lx[i][np]=min(lx[i][np],t+w);
			}
			v1[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(lx[i][j]!=1000000000000000005ll){
				v[i].push_back({j,lx[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dj(i);
	}
	while(q--){
		long long x,y;
		read(x);
		read(y);
		long long mi=1000000000000000005ll;
		for(auto i:v1[x]){
			int np1=i.first;
			long long w1=i.second;
			for(auto j:v1[y]){
				int np2=j.first;
				long long w2=j.second;
				mi=min(mi,d[np1][np2]+w1+w2);
			}
		}
		cout<<mi+a[x]+a[y]<<'\n';
	}
	return 0;
}