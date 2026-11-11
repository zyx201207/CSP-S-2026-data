#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550000],f[550000],s[550000],ss[550000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n;i>=1;i--){
		s[i]=f[a[i]];
		f[a[i]]=i;
	}
	long long k=1;
	while(k<=n){
	
	long long i=k;
	while(i<=n){
		if(s[i]){
			i=s[i];
			i--;
		}
		else{
			ss[a[i]]++;
		}
		i++;
	}
	k++;
}
	for(int i=1;i<=m;i++){
		printf("%lld ",ss[i]);
	}
	return 0;
}
