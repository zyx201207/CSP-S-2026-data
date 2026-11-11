#include<bits/stdc++.h>
using namespace std;
char a,b,s[100005];
int n,m,c,x;
string u,y;
int r[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&m,&a);
		for(int i=0;i<=m;i++){
			s[c+i]=a;
			c++;			
		}
	}
	for(int i=0;i<=n/2;i++){
		if(s[i]!=s[n-i]){
			s[n-i]=s[i];
			x++;
		}
	}
	printf("%d",x);
	return 0;
}
