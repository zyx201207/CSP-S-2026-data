#include<bits/stdc++.h>
using namespace std;
int a,n,c,s=0;
char b,d[114514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%c",&n,&b);
		c+=n;int o=0;
		for(;o<n;o++)d[s+o]=b;
	}
	n=0;
	for(int i=0;i<c/2;i++){
		if(d[i]!=d[c-i]) n++;
	}
	printf("%d",n);
	return 0;
}
