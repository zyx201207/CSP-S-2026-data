#include<bits/stdc++.h>
#define int long long
#define raed(x) read(x)
#define Spa putchar(' ')
#define Nxt puts("");
#define Pline puts("--------------")
namespace FastIO{
	int read_x,read_f,write_top;
	int write_st[25];
	char read_char;
	inline int read(int &x){
		x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			x=(x<<1)+(x<<3)+(read_char-'0');
			read_char=getchar();	
		}
		return x*=read_f;
	}
	inline int read(){
		read_x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			read_x=(read_x<<1)+(read_x<<3)+(read_char-'0');
			read_char=getchar();	
		}
		return read_x*read_f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		do{
			write_st[++write_top]=x%10;
			x/=10;
		}while(x);
		while(write_top)putchar(write_st[write_top--]+'0');
		return ;
	}
	inline void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	inline void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1,j=0;i<=n;i++){
		//find the first j 
		//a_i*i-a_i*j-a_i*pre_i-a_i*pre_j<=m
		//when i increasing,the j is increasing too
		while(a[i]*(i-j)-(pre[i]-pre[j])>m)
			j++;
		//from j+1 to i 
		tomax(ans,i-j);
	}
	write(ans),Nxt;
}
/*
  
*/ 
