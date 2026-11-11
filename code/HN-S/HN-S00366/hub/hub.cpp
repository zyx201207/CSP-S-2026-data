#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int n,c,T,k;
int h[N],cnt1;
struct Edge{
	int to,next;
}edge[N];
void add(int u,int v){
	edge[++cnt1]=Edge{v,h[u]};
	h[u]=cnt1;
}
int read(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	T=read();
	while(T--){
	    n=read();
	    k=read();
	    for(int i=1;i<n;i++){
			int u,v;
			u=read();
			v=read();
			add(u,v);
	    }
	    write((n/k)/2);
	}

    return 0;
}
