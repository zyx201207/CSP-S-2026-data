#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	vector<long long> v(n+1);
	vector<long long> hs(m+1,0);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	for(long long i=1;i<=n;i++){
		stack<long long> z;
		vector<bool> lshs(m+1,0);
		for(long long j=i;j<=n;j++){
			long long ls=v[j];
			if(lshs[ls]==0){
				z.push(ls);
				lshs[ls]=1;
			}
			else{
				while(!z.empty()&&z.top()!=ls){
					z.pop();
				}
			}
		}
		while(!z.empty()){
			hs[z.top()]++;
			z.pop();
		}
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",hs[i]);
	}
	return 0;
}