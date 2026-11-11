#include<bits/stdc++.h>
using namespace std;
#define file(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
//#define int ll
#define ll long long
#define rad read<int>
#define gc getchar
template<typename T>T read(){
	T ret=0;bool f=0;char ch;
	for(;!isdigit(ch=gc());f=!f?(ch=='-'):f);
	for(;isdigit(ch);ch=gc())ret=(ret<<3)+(ret<<1)+(ch^48);
	return f?-ret:ret;
}
#define maxn 500005
#define maxm 300005
int n,m,a[maxn],js[maxn],top,ans[maxm],lst[maxm];
signed main(){
	file(card);
	n=rad(),m=rad();
	for(int i=1;i<=n;i++)a[i]=rad();
	for(int i=1;i<=n;i++){
		top=0,memset(lst,0,sizeof lst),memset(js,0,sizeof js);
		for(int j=i;j<=n;j++){
			if(!lst[a[j]])lst[a[j]]=j,js[++top]=a[j];
			else{
				js[++top]=a[j];
				if(lst[a[j]]==top)top--;
				else{
					int go=lst[a[j]];
					for(int k=go+1;k<=top-1;k++)lst[js[k]]=0;
					top=go;
				}
				lst[a[j]]=top;
			}
		}
		for(int j=1;j<=top;j++)ans[js[j]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
