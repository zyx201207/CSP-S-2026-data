#include<bits/stdc++.h>
using namespace std;
int n;long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	int bfi=n;
	long long bfs=0;
	for(int i=n;i>0;){
		if(bfs>m){
			bfs-=(a[bfi]-a[bfi-1])*(bfi-i);
			bfi--;
		}
		else{
			if(bfi-i+1>ans){
				ans=bfi-i+1;
			}
			i--;
			bfs+=a[bfi]-a[i];
		}
	}
	printf("%d",ans);
	return 0;
}
