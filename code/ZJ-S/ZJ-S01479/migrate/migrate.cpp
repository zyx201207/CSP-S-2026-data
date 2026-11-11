#include<bits/stdc++.h>
using namespace std;
int read(){
	int t=1,l=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		l=l*10+ch-'0';
		ch=getchar();
	}
	return l*t;
}
const int MX=2e6+5;
int n,d,c,t;
int a[MX],f[MX],l[MX];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n-3;i++){
			memset(f,0,sizeof(f));
			f[i]=1,l[i]=0;
			for(int j=i+1;j<=n;j++){
				l[j]=1e9;
				for(int k=j-1;k>=i;k--){
					if(a[j]-a[k]>d) break;
					if(l[k]+1<l[j]){
						f[j]=1;
						l[j]=l[k]+1;
					}
					else if(l[k]+1==l[j]) f[j]++;
				}
				if(f[j]==2){
					ans++;
				}
				if(f[j]>2||f[j]==0) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
