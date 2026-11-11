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
	int mi,n,a[200001],l,r,answer;
	char ch[200001];
	void init(){}
	void work(){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			cin>>ch[i];
		}
		l=1,r=n;
		while(l<r){
			mi=min(a[l],a[r]);
			if(ch[l]!=ch[r]) answer+=mi;
			a[l]-=mi;
			a[r]-=mi;
			if(a[l]==0) l++;
			if(a[r]==0) r--;	
		}
		output(answer);
		return ;
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	Czming__::init();
	while(T--) Czming__::work();
	return 0;
}
/*
cd /d E:\ZJ-J00406\string
fc string1.out string1.ans
fc string2.out string2.ans
fc string3.out string3.ans
fc string4.out string4.ans
fc string5.out string5.ans
fc string6.out string6.ans
*/
