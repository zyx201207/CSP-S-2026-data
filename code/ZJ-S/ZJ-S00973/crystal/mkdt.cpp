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
int frand(){return (rand()&1)?-brand():brand();}
signed main(){
	freopen("crystal.in","w",stdout);
	srand(GetTickCount());
	printf("%d %d\n",n=rand()%5000+1,m=brand());
	for(int i=1;i<=n;i++) printf("%d ",frand());
	return 0;
}
