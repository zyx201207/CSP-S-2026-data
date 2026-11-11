#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,nxt;
}a[2000010];
int c,t,n,k,head[1000010],tot;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(!x) return ;
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}
