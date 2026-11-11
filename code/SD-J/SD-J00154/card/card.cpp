#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m,a[N],l,ans[N];
bool li[N];
int c[N];
int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		l=0;
		for(int o=i;o<=n;o++){
			for(int j=1;j<=l;j++){
				if(c[j]==a[o]){
					l=j-1;
					break;
				}
			}
			c[++l]=a[o];
		}
		for(int j=1;j<=l;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
