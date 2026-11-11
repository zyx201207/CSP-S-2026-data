#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005]={1073741823};
long long dfs(long long x,long long y,long long pre){
	if(y==0) return pre;
	if(x==y) return (s[x]&pre);
	return max(dfs(x-1,y-1,(a[x]&pre)),dfs(x-1,y,pre)); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=(a[i]&s[i-1]);
	}
	printf("%lld",dfs(n,m,1073741823));
	return 0;
} 
