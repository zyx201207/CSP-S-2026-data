#include<bits/stdc++.h>
using namespace std;

int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();int T=read();
	while(T--){
		int n=read(),k=read();
		printf("%d\n",n*k-n-k);
	}
	return 0;
}
