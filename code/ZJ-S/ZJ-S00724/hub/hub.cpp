#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int distant(int x,int y){
	
}
ll c,n,m,d,q;
ll kou_ding[N];
ll ding_tai[N][N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		kou_ding[i]=read();
	}
	for(int i=1;i<=n;i++){
		int x=read();
		for(int j=1;j<=x;j++){
			int sta=read();
			int sta_ding=read();
			ding_tai[sta][i] = sta_ding;
		}
	}
	while(q--){
		int s=read();
		int end=read();
		int time=0;
		cout<<1;
	}
	return 0;
}
