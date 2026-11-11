#include<bits/stdc++.h>
using namespace std;
bool flg[300005];
int n,m,a[500005],ans[300005],nxt[500005],lst[300005];
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(lst[a[i]]){
			nxt[lst[a[i]]]=i;
		}
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int ps=i;
		while(ps<=n){
			flg[a[ps]]=1;
			if(nxt[ps])ps=nxt[ps];
			ps++;
		}
		for(int j=1;j<=m;j++)ans[j]+=flg[j],flg[j]=0;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}