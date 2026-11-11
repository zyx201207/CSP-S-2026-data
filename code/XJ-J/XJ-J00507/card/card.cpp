#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<long long> a;
	scanf("%lld %lld",&n,&m);
	const long long MAXM=m+2,MAXN=n+2;
	long long lx[MAXM],sy[MAXN],v[MAXM];
	for(int i=1;i<=n;i++){
		scanf("%lld",&sy[i]);
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		int z=a.size();
		while(z--){
			a.pop_back();
		}
		for(int j=1;j<=n;i++){
			if(v[sy[i]]!=0){
				int k=i-v[sy[i]];
				while(k--){
					a.pop_back();
					v[k]=0;
				}
				a.push_back(sy[i]);
				v[sy[i]]=i;
			}else{
				a.push_back(sy[i]);
				v[sy[i]]=i;
			}
		}	
		for(int j=0;j<a.size();i++){
			lx[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld",lx[i]);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
