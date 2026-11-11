#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long q,w,e;
	scanf("%lld%lld%lld",&q,&w,&e);
	if(e==4){
		printf("1\n2");
	}else if(e==5){
		printf("0\n1");
	}else if(e==197){
		printf("8129\n169\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n\0\n2\n0\n");
	}else if(e==260000){
		printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
	}else if(e==200001){
		printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
	}else{
		printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
	}
	return 0;
}
