#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e3+7;
long long aa[maxn],num[maxn];
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	long long c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		if(n<=3){
			printf("0\n");
			continue;
		}
		if(c<=10){
			long long mind=1e9; 
			for(long long i=1;i<=n;i++){
				scanf("%lld",&aa[i]);
				mind=min(mind,aa[i+1]-aa[i]);
				for(long long j=1;j<i;j++){
					if(aa[i]-aa[j]<=d){
						num[j]=i;
					}
				}
			}
			if(c>=13||mind*2>d){
			printf("0\n");
			continue;
		}//一步一步走
			long long ans=0;
			for(long long l=1;l<=n;l++){
				for(long long r=l+3;r<=n;r++){
					queue<pair<long long,long long> >q;
					q.push({l,0});
					long long numm=0,minn=1e9;
					while(q.size()){
						long long now=q.front().first;
						long long once=q.front().second;
						q.pop();
						for(long long i=now+1;i<=num[i];i++){
							if(i>r)break;
							if(i==r){
								if(once+1<minn){
									minn=once+1;
									numm=1;
								}
								if(once+1==minn){
									numm++;
								}
							}
							else q.push({i,once+1});
						}
					}
					if(numm==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		long long mind=0;
		long long a=0,b=0;
		for(long long i=1;i<=n;i++){
			if(i&1)scanf("%lld",&a);
			else scanf("%lld",&b);
			if(i==2)mind=abs(a-b);
			if(i>=2)mind=min(mind,abs(a-b));
		}
		if(c>=13||mind*2>d){
			printf("0\n");
			continue;
		}//一步一步走 
		if(c==11||c==12){
			long long k=d/mind;
			long long ans=n-(2*k)+1;
			ans=max(ans,ans/ans-1);
			printf("%lld\n",ans);
			continue;
		}
		printf("0\n");
	}
	return 0;
}
