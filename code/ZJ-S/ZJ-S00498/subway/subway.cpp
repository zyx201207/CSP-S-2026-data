#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[501],k[500001][21],ki[500001],x,y;
inline int read(){
	int res=0;
	int flag=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){
		flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	if(flag==-1)return -res;
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		ki[i]=read();
		for(int j=1;j<=ki;j++){
			k[i][j]=read();
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
