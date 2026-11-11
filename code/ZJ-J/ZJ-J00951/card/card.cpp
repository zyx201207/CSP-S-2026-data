#include<bits/stdc++.h>
using namespace std;
long long ton[300005];
bool check(long long a[],long long n,long long b){
	for(long long i=0;i<n;i++){
		if(a[i]==b)
			return true;
	}
	return false;
}
bool check_up(long long a[],long long n){
	for(long long i=1;i<n;i++)
		if(a[i]<a[i-1])
			return false;
	return true;
}
int find(long long a[],long long n,long long b){
	for(long long i=0;i<n;i++){
		if(a[i]==b)
			return i;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long a[n];
	for(long long i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(check_up(a,n)){
		for(long long i=0;i<n;i++){
			bool vis[300005];
			memset(vis,1,sizeof(vis));
			for(long long j=i;j<n;j++)
				if(vis[a[j]]){
					ton[a[j]]++;
					vis[a[j]]=0;
				}
		}
		for(long long i=1;i<=m;i++)
			printf("%lld ",ton[i]);
		return 0;
	}
	for(long long i=0;i<n;i++){
		long long card[n],op=0;
		memset(card,0,sizeof(card));
		for(long long j=i;j<n;j++){
			if(check(card,n,a[j])){
				int goal=find(card,n,a[j]);
				for(long long k=goal;k<n;k++){
					card[k]=0;
					if(card[k+1]==0){
						break;
					}
				}
				card[goal]=a[j];
				op=goal+1;
			}
			else{
				card[op]=a[j];
				op++;
			}
		}
		for(long long i=0;i<n;i++){
			if(card[i]==0)
				break;
			ton[card[i]]++;
		}
	}
	for(long long i=1;i<=m;i++)
		printf("%lld ",ton[i]);
	return 0;
}
