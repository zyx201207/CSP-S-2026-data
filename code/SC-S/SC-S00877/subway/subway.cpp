#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ff=1;
const int N=1e9+7;
struct node{
	long long v,u; 
};
vector<node>st[510005];
char buf[1<<22],*p1,*p2;
char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,1<<22,stdin);
	if(p1==p2)return EOF;
	else return *p1++;
} 
long long readlong(){
	long long f=1,s=0;
	char yb=gc();
	while(yb<'0'&&yb>'9'){
		if(yb=='-')f=-1;
		yb=gc();
	}
	while(yb>='0'&&yb<='9'){
		s=s*10+yb-'0';
		yb=gc();
	}
	return s*f;
}
long long dij(int l,int r){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >pq; 
	pq.push({0,l});
	vector<long long>minn(n+m+100,N);
	minn[l]=0;
	while(int(pq.size())>0){
		int len=pq.top().first,jd=pq.top().second;
		pq.pop();
		for(int i=0;i<int(st[jd].size());i++){
			int d=st[jd][i].u,l=st[jd][i].v;
			if(l+len<minn[d]){
				minn[d]=l+len;
				pq.push({minn[d],d});
			}
		}
	} 
	return minn[r];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=readlong();
	n=readlong();
	m=readlong();
	d=readlong();
	q=readlong();
	vector<long long>w(m+5);
	for(int i=1;i<=m;i++)w[i]=readlong();
	for(int i=1;i<=n;i++){
		long long k;
		k=readlong();
		for(int j=1;j<=k;j++){
			long long x,y;
			x=readlong();
			y=readlong();
			st[x].push_back({y,i+m});
			st[i+m].push_back({y,x});
		}
	}	
	while(q--){
		int l,r;
		l=readlong();
		r=readlong();
		printf("%lld\n",dij(l,r)+w[l]+w[r]);
	}
	return 0;
}
