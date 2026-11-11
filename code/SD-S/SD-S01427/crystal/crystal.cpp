#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
const int MAXN=5e6+5;

i128 a[MAXN];
i128 pre[MAXN];
i128 read(){
	i128 f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(i128 x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)+'0');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr); 
	i128 n,m;
	i128 maxx=1,now=0;
	i128 idx=1;
	n=read();
	m=read();
	for(i128 i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(i128 i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1;
	while(l<=n){
		while((pre[l-1]-pre[idx-1]+m<(l-idx)*(a[l]))&&(idx<l)){
			now--;
			idx++;
		}
		now++;
		//write(now);
		//putchar(' ');
		maxx=max(maxx,now);
		l++;
	}
	write(maxx);
	return 0;
}
