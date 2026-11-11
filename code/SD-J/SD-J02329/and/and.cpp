#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+7;
int n,m,a[N];
long long maxx;
void getu(int aa,int b,int ans){
	if(!b){
		if(ans>maxx)maxx=ans;
		return;
	}
	for(int i=b;i<=aa;i++){
		if(b==m)getu(i-1,b-1,a[i]);
		else getu(i-1,b-1,ans&a[i]);
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	getu(n,m,0); 
	printf("%lld\n",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
