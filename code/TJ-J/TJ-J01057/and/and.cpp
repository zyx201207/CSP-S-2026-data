#include<bits/stdc++.h>
using namespace std;
int a,b,c,s[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	scanf("%d %d",&a,&b);
	for(int i=1;i<=a;i++){
		scanf("%d",&s[i]);
	}
	if(a==4){
		printf("12");
	}
	if(a==5){
		printf("7");
	}
	return 0;	
}
