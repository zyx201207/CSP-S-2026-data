#include<bits/stdc++.h>
#include<windows.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,m;
int brand(){return (rand()<<16)|(rand()<<1)|(rand()&1);}
signed main(){
	freopen("string.in","w",stdout);
	srand(GetTickCount());
	n=rand()%20+1,m=rand()%n+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d ",brand()%((1<<30)+1));
	}
	return 0;
}
