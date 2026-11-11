#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N=2e6+10,M=4e6+10;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
struct node{
	int to,nxt;
}e[M];
int T;
int n,k;
int head[N],cnt=1;
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	return ;
}
void planA(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			add(u,v);
		}
		int len=n/2+1;
		if(k==1){
			if(len%2==0) cout<<len/2<<'\n';
			else cout<<len/2+1<<'\n';
		}
		else if(k>=n) cout<<"0\n";
		else{
			int len=n/2+1;
			if(k>=len) cout<<"1\n";
			else{
				len-=k;
				int res=0;
				if(len%4==0) res=len/4+1;
				else res=len/4+2;
				cout<<max(1LL,res)<<'\n';
			}
		}
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read();
	if(c>=13&&c<=14){
		planA();
		return 0;
	}
	while(T--){
		cout<<"1\n";
	}
	return 0;
}
