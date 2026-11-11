#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N],q,g[N],p[N],dfg=1;
struct er{
	long long xb;
	long long gs; 
	long long dy;
}b[N];
long long f(long long a){
	long long b;
	while(a){
		if(a%2==1) b++;
		a/=2;
	}
	return b;
}
long long ejr(long long a){
	long long b=0;
	while(a){
		b++;
		a/=2;
	}
	return b;
}
bool cmp(er s,er d){
	return s.gs>d.gs;
}
bool cmp2(er s,er d){
	return s.dy>d.dy;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	if(m==1){
		long long qwe=-1;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			qwe=max(qwe,a[i]);
			cout<<qwe;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i].gs=f(a[i]);
		b[i].xb=i;
		b[i].dy=ejr(a[i]);
	}
	sort(b+1,b+n+1,cmp);
	for(long long i=1;i<=n;i++){
		if(b[i].gs==b[i+1].gs&&b[i].gs!=b[i-1].gs) p[dfg]=i;
		if(b[i].gs==b[i-1].gs&&b[i].gs!=b[i+1].gs){
			g[dfg]=i;
			dfg++;
		}
	}
	for(long long i=1;i<=dfg;i++) sort(b+p[i],b+g[i],cmp2);
	q=a[b[1].xb]&a[b[2].xb];
	for(long long i=3;i<=m;i++) q=q&a[b[i].xb];
	cout<<q;
	return 0;
}
