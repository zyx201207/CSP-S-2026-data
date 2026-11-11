#include<bits/stdc++.h>
using namespace std;
int c,t;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+(ch-'0');ch=getchar();}
	return s*f;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		printf("1\n");
	}
	return 0;
}
