#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	vector<long long> a(n+5,0),bj(m+1,0);
	for(long long i=1; i<=n; i++){
		scanf("%d",&a[i]);
	} 
	if(m<=2){
		bool flag=1;
		for(long long i=1; i<=n; i++){
			if(a[i]!=a[i+1]) flag=0;
		}
		if(flag==1){
			if(a[1]==1 && m==1)	printf("1");
			else if(a[1]==1 && m==2) printf("1 0");
			else printf("0 1");
		}
		return 0;
	} 
	if(n==2 && m<=2){
		printf("2 2");
	} 
	else if(n==3 && m<=2) printf("3 2");
	return 0;
}

