#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
int n,m,a[500005],stk[500005],top,ans[500005];
bool hv[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
//	if(n<=5000&&m<=3000){
//		for(int st=1;st<=n;st++){
//			memset(hv,0,sizeof hv);top=0;
//			for(int i=st;i<=n;i++){
//				if(hv[a[i]]) while(top&&stk[top]!=a[i]) hv[stk[top--]]=0;
//				else hv[a[i]]=1,stk[++top]=a[i];
//			}
//			for(int i=1;i<=top;i++) ans[stk[i]]++;
//		}
//		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		//1~12 48pts
		//O(n^2)
//	}else{
		//就看数据水不水了
		int jmp[300005];memset(jmp,0,sizeof jmp);
		for(int i=1;i<=n;i++) jmp[a[i]]=i;
		for(int st=1;st<=n;st++){
			for(int i=st;i<=n;i++){
				ans[a[i]]++,i=jmp[a[i]];
			}
		}
		for(int i=1;i<=m;i++) printf("%d ",ans[i]);
		//O(nm) 最坏
		//大概能过1~17，68pts
//	}
	return 0;
}
