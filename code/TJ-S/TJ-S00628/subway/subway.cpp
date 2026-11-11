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
int c,n,m,d,q,k,rd1,rd2,head[502],w[500002],tot[500002];
long long ans,f[502][502];
struct Nephren{
	int id,tm;
};
Nephren mp[500002][22];
void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read<int>(),n=read<int>(),m=read<int>(),d=read<int>(),q=read<int>();
	for(int i=1;i<=m;++i)w[i]=read<int>();
	for(int i=1;i<=n;++i){
		k=read<int>();
		for(int j=1;j<=k;++j){
			rd1=read<int>(),rd2=read<int>();
			mp[rd1][++tot[rd1]]={i,rd2};
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;++i){
		for(int j=1;j<=tot[i];++j){
			for(int k=1;k<=tot[i];++k){
				f[mp[i][j].id][mp[i][k].id]=min(f[mp[i][j].id][mp[i][k].id],0ll+mp[i][j].tm+mp[i][k].tm);
			}
		}
	}
	for(int i=1;i<=n;++i)f[i][i]=0;
	floyd();
	while(q--){
		rd1=read<int>(),rd2=read<int>();
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=tot[rd1];++i){
			for(int j=1;j<=tot[rd2];++j){
				ans=min(ans,0ll+w[rd1]+mp[rd1][i].tm+f[mp[rd1][i].id][mp[rd2][j].id]+mp[rd2][j].tm+w[rd2]);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
