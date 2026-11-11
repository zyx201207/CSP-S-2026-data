#include<bits/stdc++.h>
inline long long read(){
	long long a=0;
	int b=1;
	char c=getchar();
	if(c<'0'||c>'9'){
		if(c=='-'){
			b=-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
inline void write(long long a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a<10){
		putchar(a+'0');
		return;
	}
	write(a/10);
	putchar(a%10+'0');
}
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long N,len=0;
	scanf("%lld",&N);
	char A[2000000]; 
	for(int i=0;i<N;i++){
		int a;
		char b,c;
		scanf("%d%c%c",&a,&c,&b);
		//cout<<a<<" "<<b<<"\n";
		for(int j=0;j<a;j++){
			A[len++]=b;
		} 
	}
	/*
	for(int i=0;i<len;i++){
		cout<<A[i];
	}
	*/
	long long num=0;
	for(int i=0;i<len/2;i++){
		if(A[i]!=A[len-i-1]){
			num++;
		} 
	}
	write(num);
	return 0;
} //3 2 a 2 b 1 c
