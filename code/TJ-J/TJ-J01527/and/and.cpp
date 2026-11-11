#include <bits/stdc++.h>
using namespace std;
const int N=2e5+62;
int n,m,a[N],c[N]={0},s=0;
void trickortreat(int x,int y){
	if(x>m){
		s=max(s,y);
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=1){
			c[i]=1;
			if(x==1) trickortreat(x+1,a[i]);
			else trickortreat(x+1,y&a[i]);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	trickortreat(1,0);
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
