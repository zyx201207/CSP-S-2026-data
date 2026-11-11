#include <cstdio>
#include <cstring>
const int MAXN=7;
char c1[MAXN],c2[MAXN],s1[MAXN],s2[MAXN];
char check1[MAXN];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1[1],&s1[1],&c2[1],&s2[1]);
	int n=std::strlen(&c1[1]);
	int m=std::strlen(&s1[1]);
	for(int i=1;i<=n;i++){
		if(c1[i]!=c2[i]){
			printf("0000\n");
			return 0;
		}
	}
	for(int i=1;i<=m-1;i++){
		if(s1[i]!=s2[i]){
			printf("1000\n");
			return 0;
		}
	}
	check1[1]='A';
	check1[2]='B';
	check1[3]='C';
	bool o=false,k=false;
	for(int i=1;i<=3;i++){
		if(s1[m]==check1[i]) o=true;
	}
	for(int i=1;i<=3;i++){
		if(s2[m]==check1[i]) k=true;
	}
	if(o!=k){
		printf("1100\n");
		return 0;
	}
	if((s1[m]=='A'&&s2[m]=='C')||(s1[m]=='C'&&s2[m]=='A')){
		printf("1110\n");
		return 0;
	}
	printf("1111\n");
	return 0;
} 
