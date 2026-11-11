#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[1000006],f[1000005];
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch == '-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch <='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	for(int i=1;i<=t;i++){
		fill(a,a+100002,0);
		fill(f,f+100002,0);
		n=read(),d=read();
		for(int j=1;j<=n;j++){
			a[j]=read();
		}
		for(int j=1;j<=n;j++){
			f[j]+=f[j-1];
			if(a[j+3]-a[j]>d && a[j+3]-a[j]<2*d){
				f[j+3]++;
			}
		}
		int l=1;
		for(int j=2;j<=n;j++){
			if(a[j]-a[j-1]>d){
				l=j;
			}
			if(f[j]-f[l] == 1 && f[a[j]]-f[a[j-1]]<=d){
				f[j]+=j-3-l;
			}
			else if(f[j]-f[l]>1){
				l=j-3;
			}

		}
		cout << f[n]<< endl;
	}
	return 0;
}
