#include <bits/stdc++.h>
using namespace std;
int n,m,h;
int s1,s2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1");
		return 0;
	}
	scanf("%d",&s1);
	scanf("%d",&s2);
	h=s2-s1;
	h=abs(h);
	int i=1,ans=0;
	while(m>=i*h){
		m-=i*h;
		i++;
		ans++;
	}
	printf("%d",min(ans,n));
	return 0;
}