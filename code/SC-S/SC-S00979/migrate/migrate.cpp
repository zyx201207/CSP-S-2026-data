#include<bits/stdc++.h>
using namespace std;
int c,t;
unsigned long long n,d;
long long x[2000005];
int bfs(long long i,long long j){
	queue<long long> w,deep;
	w.push(i);
	deep.push(0);
	long long ans=-1,cnt=0;
	while(!w.empty()){
		long long nw=w.front();
		long long nd=deep.front();
		w.pop();
		deep.pop();
		long long s=nw+1;
		if(nw==j){
			if(ans==-1){
				ans=nd;
				cnt++;
			}else if(ans==nd){
				cnt++;
			}else{
				break;
			}
		}
		while(s<=j&&abs(x[s]-x[nw])<=d){
			if(x[s]<x[nw])cout<<"error";
			w.push(s);
			deep.push(nd+1);
			s++;
		}
	}
	return cnt==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		int ans=0;
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				ans+=bfs(i,j);
			}
		}
		cout<<ans<<'\n';
	}
    return 0;
}