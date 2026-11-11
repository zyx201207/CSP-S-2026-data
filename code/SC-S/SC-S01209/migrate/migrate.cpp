#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
void f(int a,int b){
	if(a%b==0){
		printf("1\n");
		return;
	}
	if(a%b==1){
		printf("2\n");
		return ;
	}
	if(a%b==2){
		printf("0\n");
		return ;
	}
}
int main(){
	freopen("migraate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	ll t,n[10001],d[10001],x[10001];
	scanf("%d %lld",&c,&t);
	for(int i=1;i<=t;++i){
		scanf("%lld %lld",&n[i],&d[i]);
		for(int j=1;j<=n[i];++j){
			scanf("%lld",&x[j]);
		}
	}
	for(int i=1;i<=t;++i){
		for(int j=1;j<=n[i];++j){
			f(n[j],d[j]);
		}
	}
	return 0;
}