#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n;
long long ans;
struct CYC{
	int num;
	char ch;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i].num=read();
		char x=getchar();
		while(x<'a'||x>'z')x=getchar();
		a[i].ch=x;
	}
	int L=1,R=n;
	while(L<R){
		if(a[L].ch!=a[R].ch){
			if(a[L].num<a[R].num)ans+=a[L].num,a[R].num-=a[L].num,L++;
			else if(a[L].num>a[R].num)ans+=a[R].num,a[L].num-=a[R].num,R--;
			else ans+=a[L].num,L++,R--;
		}else{
			if(a[L].num<a[R].num)a[R].num-=a[L].num,L++;
			else if(a[L].num>a[R].num)a[L].num-=a[R].num,R--;
			else L++,R--;
		}
	}
	printf("%lld",ans);
	return 0;
}