#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace io{
	int read(){
		int x=0,y=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') y=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
		return x*y;
	}
	void output(int x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9) output(x/10);
		putchar(x%10|48);
	}
}
#define read() io::read()
#define output(x) io::output(x)
namespace Czming__{
	string c1,s1,c2,s2;
	int sum1,sum2;
	char ch1,ch2;
	void print(int x){
		for(int i=1;i<=x;i++) putchar('1');
		for(int i=x+1;i<=4;i++) putchar('0');
	}
	void init(){return ;}
	void work(){
		sum1=read();
		cin>>s1;
		sum2=read();
		cin>>s2;
		if(sum1!=sum2){
			print(0);
			return ;
		}
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			print(1);
			return ;
		}
		ch1=s1[2];
		ch2=s2[2];
		if(ch1>ch2) swap(ch1,ch2);
		if(ch1<='C'&&'D'<=ch2){
			print(2);
			return ;
		}
		if(ch2-ch1==1||(ch2=='F'&&ch1=='D')){
			print(4);
			return ;
		}
		print(3);
		return ;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	Czming__::init();
	while(T--) Czming__::work();
	return 0;
}
/*
cd /d E:\ZJ-J00406\travel
fc travel1.out travel1.ans
fc travel2.out travel2.ans
fc travel3.out travel3.ans
fc travel4.out travel4.ans
fc travel5.out travel5.ans
*/
