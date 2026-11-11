#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,j=0,sum=0;
	scanf("%d",&n);
	char s[250000];
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		char ch,c;
		scanf("%c%c",&c,&ch);
		for(int x=1;x<=k;x++){
			s[++j]=ch;
		}
	}
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]!=s[l-i+1]){
			sum++;
		} 
	} 
	printf("%d",sum/2);
	return 0;
}
