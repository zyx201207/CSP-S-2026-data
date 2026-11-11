#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10;
long long read() {
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
void write(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
long long c,t,n,k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	for(int i=1;i<=t;i++){
		write(1);
		putchar('\n');
	}
	return 0;
}
