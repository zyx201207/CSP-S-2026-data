#include<bits/stdc++.h>
using namespace std;

int Read(){
	char c=' ';
	bool f=0;
	while(!('0'<=c&&c<='9')){
		c=getchar();
		if(c=='-') f=1;
	}
	int res=0;
	while('0'<=c&&c<='9'){
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	if(f) res=-res;
	return res;
}
void Write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",a+b);
	return 0;
}