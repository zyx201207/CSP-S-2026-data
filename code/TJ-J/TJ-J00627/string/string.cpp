#include<bits/stdc++.h>
using namespace std;

int n,a[200010],b[200010],c[300000000000000],e[200000000000000];
int d = 0,f = 0;

int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i];j++){
			c[j+d] = b[i];
			d++;
		}
	}
	for(int i =d;i >= d-d/2;i--){
		e[d-i+1] = c[i];
	}
	
	for(int i = 1;i <= d /2;i++){
		if(c[i] != e[i]){
			f++;
		}
	}
	printf("%d",f);
	
	printf("\n\n\n\n%d\n",clock());
	return 0;
}
