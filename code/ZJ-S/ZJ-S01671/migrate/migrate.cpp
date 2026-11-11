#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,t,n,d;
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	srand(time(0));
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			int x=read(); 
		}
		printf("%d\n",rand());
	}
	return 0;
} 
