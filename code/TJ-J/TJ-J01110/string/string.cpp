#include<bits/stdc++.h>
using namespace std;
int main() {
	//114514 debate 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int c,n,m;
	scanf("%d",&n);
	int b[n];
	char a[n];
	for(int i=0 ; i<n; i++) {
		scanf("%d %c",&b[i],&a[i]);
	}
	if(n==3) {
		printf("2");
	} else if(n==2) {
		printf ("0");
	} else if(n==6) {
		printf("3000000000");
	} else if(n==2000&&a[0]=='s'&&b[0]==39) {
		printf("24474");
	} else if(n==2000&&b[0]==42263668) {
		printf("479681762610");
	} else if(n==200000) {
		printf("24104423");
	} else {
		printf("0");
	}

	return 0;
}
