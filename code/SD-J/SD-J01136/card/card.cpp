#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],v[500005],ans[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--){
		if(!v[a[i]])
			v[a[i]]=i;
		b[i]=1;}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=b[i];
		b[v[a[i]]+1]+=b[i];}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
