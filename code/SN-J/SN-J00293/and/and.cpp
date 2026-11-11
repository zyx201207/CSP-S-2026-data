#include<bits/stdc++.h>
using namespace std;
int c[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int a;
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+a+1);
	printf("%d",c[b]);
	return 0;
} 
