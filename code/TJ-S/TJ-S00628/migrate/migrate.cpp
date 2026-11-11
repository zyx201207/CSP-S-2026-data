#include<iostream>
#include<cstdlib>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
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
int c,t,n,f[2000002],g[2000002],pre[2000002],nxt[2000002],val[2000002];
long long ans,d,x[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read<int>(),t=read<int>();
	while(t--){
		n=read<int>(),d=read<long long>();
		for(int i=1;i<=n;++i)x[i]=read<long long>();
//		if(c==11||c==12){
//			if(n==1){
//				printf("0\n");
//				continue;
//			}
//			int r=d/(x[2]-x[1]);
//			if(r<2)printf("0\n");
//			else printf("%d\n",max(n-(r*2-1),0));
//			continue;
//		}
		ans=0;
		for(int i=1,p=1;i<=n;++i){
			while(x[p]<x[i]-d)++p;
			pre[i]=p;
		}
		for(int i=1;i<=n;++i)val[i]=0;
		for(int i=n,p=n;i;--i){
			while(x[p]>x[i]+d)--p;
			nxt[i]=p;
			if(i!=p)++val[p];
		}
//		for(int i=1;i<=n;++i){
//			int tmp1,tmp2=i,p=pre[i];
//			bool mark=0;
//			while(p!=pre[p]){
//				tmp1=tmp2,tmp2=p,p=pre[p];
//				if(mark)ans+=val[tmp2];
//				else if(tmp2+1!=tmp1&&(tmp1==i||nxt[tmp2+1]==tmp1))ans+=val[tmp2+1];
//				if(nxt[p]>tmp2+1)break;
//				if(nxt[p]==tmp2+1){
//					if(mark==1||(tmp1!=i&&nxt[tmp2+1]!=tmp1))break;
//					mark=1;
//				}
//			}
//		}
//		printf("%lld\n",ans);
//		continue;
//		for(int s=1;s<=n;++s){
//			f[s]=0,g[s]=1;
//			for(int t=s+1;t<=n;++t){
//				f[t]=0x3f3f3f3f,g[t]=0;
//				for(int v=max(s,pre[t]);v<t;++v){
//					if(f[v]+1<f[t]){
//						f[t]=f[v]+1;
//						g[t]=g[v];
//					}
//					else if(f[v]+1==f[t])g[t]+=g[v];
//					else break;
//					if(g[t]>2)break;
//				}
//				if(!g[t])break;
//				if(g[t]==2)++ans;
//			}
//		}
//		printf("%lld\n",ans);
		for(int i=1;i<=n;++i){
			f[i]=val[i],g[i]=0;
			if(i!=pre[i]&&nxt[pre[i]]==i){
				f[i]+=f[pre[i]];
				g[i]+=g[pre[i]];
			}
			else if(i!=pre[i]){
				ans+=g[pre[i]];
			}
			if(pre[i]!=pre[pre[i]]&&nxt[pre[pre[i]]]==pre[i]+1){
				if(nxt[pre[i]+1]>i)ans+=f[pre[pre[i]]];
				else g[i]+=f[pre[pre[i]]];
			}
			if(pre[i]+1<i){
				if(nxt[pre[i]+1]>i)ans+=val[pre[i]+1];
				else g[i]+=val[pre[i]+1];
			}
		}
		for(int i=1;i<=n;++i)ans+=g[i];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
