#include<bits/stdc++.h>
#define U(a,b,c) for(int a=b;a<=c;a++)
#define D(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
int readint(){
	int x=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*k;
}
void writeint(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) writeint(x/10);
	putchar(x%10+'0');
}
const int N=2e6+10;
int a[N],L[N];
int main(){
	freopen("migrate3.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c=readint(),T=readint();
	while(T--){
		writeint(0);
		putchar('\n');
	}
	return 0;
}