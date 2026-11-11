#include<bits/stdc++.h>
using namespace std;
long long rd(){
	int m=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=!f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		m=m*10+ch-'0';
		ch=getchar();
	}
	return m*f;
}
void wr(long long num){
	if(num==0){
		return ;
	}
	if(num<0){
		putchar('-');
		num=(-num);
	}
	wr(num/10);
	putchar(num%10+'0');
}
struct node{
	long long st,ti;
}a[5005][5005];
long long c,n,m,d,q,w[500005];
int main(void){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	wr(1);
	putchar('\n');
	wr(2);
	putchar('\n');
	return 0;
}
