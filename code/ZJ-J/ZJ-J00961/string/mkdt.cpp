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
int n;
signed main(){
	freopen("string.in","w",stdout);
	srand(GetTickCount());
	n=rand()%1000+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d %c\n",rand()%2000+1,rand()%26+'a');
	}
	return 0;
}
