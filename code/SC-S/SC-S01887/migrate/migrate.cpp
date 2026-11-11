#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[5005],sum;
struct stu{
	long long p,stp;
};
long long bfs(long long x,long long y){
	queue<stu>q;
	stu nw,nt;
	long long mnj=0x3f3f3f,cnt=0;
	nw.p=x,nw.stp=0;
	if(y==x+1) return 0;
	q.push(nw);
	while(!q.empty()){
		nw=q.front(),q.pop();
		if(nw.p==y){
			if(nw.stp<mnj) mnj=nw.stp,cnt=1;
			else if(nw.stp==mnj) cnt++;
		}
		for(int i=1;a[nw.p+i]<=a[nw.p]+d&&nw.p+1<=y;i++){
			nt.p=nw.p+i,nt.stp=nw.stp+1;
			if(a[nw.p+i]<=a[nw.p]+d&&nw.p+1<=y) q.push(nt);
		}
	}
	return cnt==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		sum=0;
		scanf("%lld%lld",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				sum+=bfs(j,k);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}