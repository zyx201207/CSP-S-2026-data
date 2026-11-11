#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define ROF(i,x,y) for(int i=(x);i>=(y);i--)
#define EDGE(i,u) for(int i=head[u];~i;i=e[i].nxt)
#define pb push_back 
#define fi first
#define se second
#define meowania_Fan 0
int read(){
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}

const int N=1e5+5;


void Meowania(){
	int luogu_uid=945321;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int t=read();
	while(t--) Meowania();
	
	return meowania_Fan;
} 
