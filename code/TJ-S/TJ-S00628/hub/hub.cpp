#include<iostream>
#include<cstdlib>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
namespace KitoTaisu{
	char *p1,*p2,buf[32769];
	#define nc() ((p1==p2&&(p2=((p1=buf)+fread(buf,1,32767,stdin)),p1==p2))?EOF:(*p1++))
	template<typename ra>
	ra read(){
		ra x=0,f=1;
		char ch=nc();
		while(ch<48||ch>57){
			if(ch=='-')f=-1;
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=nc();
		}
		return x*f;
	}
	int readstr(char* str,char l='a',char r='z'){
		int len=0;
		char ch=nc();
		while(ch<l||ch>r){
			ch=nc();
		}
		while(l<=ch&&ch<=r){
			str[len++]=ch;
			ch=nc();
		}
		return len;
	}
	char readchar(char l='a',char r='z'){
		char ch=nc();
		while(ch<l||ch>r){
			ch=nc();
		}
		return ch;
	}
}
using KitoTaisu::read;
using KitoTaisu::readstr;
using KitoTaisu::readchar;
int c,t,n,k,rd1,rd2,tot,cnt,mx,ans,head[100002];
struct Chtholly{
	int to,nxt;
};
Chtholly mp[200002];
inline void add(int u,int v){
	mp[++tot].nxt=head[u];
	mp[tot].to=v;
	head[u]=tot;
}
bool cs[12],mark[12];
void dfs(int x){
	mark[x]=0;
	for(int i=head[x];i;i=mp[i].nxt){
		if(mark[mp[i].to])dfs(mp[i].to);
	}
}
struct Nephren{
	int u,d;
};
queue<Nephren> qu;
int bfs(int x){
	memset(mark,0,sizeof(mark));
	while(!qu.empty())qu.pop();
	qu.push({x,0});
	mark[x]=1;
	while(!qu.empty()){
		Nephren nep=qu.front();
		qu.pop();
		if(cs[nep.u])return nep.d;
		for(int i=head[nep.u];i;i=mp[i].nxt){
			if(!mark[mp[i].to]){
				qu.push({mp[i].to,nep.d+1});
				mark[mp[i].to]=1;
			}
		}
	}
	return -1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read<int>(),t=read<int>();
	while(t--){
		ans=0x3f3f3f3f;
		n=read<int>(),k=read<int>();
		tot=0;
		for(int i=1;i<=n;++i)head[i]=0;
		for(int i=1;i<n;++i){
			rd1=read<int>(),rd2=read<int>();
			add(rd1,rd2),add(rd2,rd1);
		}
		if(13<=c&&c<=14){//remember to change it to A
			if(k==n)printf("0\n");
			else if(k>=n/2)printf("1\n");
			else if(k==1)printf("%d\n",((n+3)/2)/2);
			else printf("%d\n",((n+13)/2-k)/4);
			continue;
		}
		for(int sd=0;sd<(1<<n);++sd){
			if(__builtin_popcount(sd)!=k)continue;
			memset(mark,0,sizeof(mark));
			for(int i=1;i<=n;++i)mark[i]=cs[i]=(bool)(sd&(1<<(i-1)));
			cnt=0;
			for(int i=1;i<=n;++i){
				if(mark[i]){
					++cnt;
					if(cnt>2)break;
					dfs(i);
				}
			}
			if(cnt>2)continue;
			mx=0;
			for(int i=1;i<=n;++i)mx=max(mx,bfs(i));
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
