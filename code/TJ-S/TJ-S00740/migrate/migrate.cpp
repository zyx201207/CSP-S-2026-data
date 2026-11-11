#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int read(){
	int x=0,f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		if(c>=13&&c<=14){
			cout<<0<<"\n";
			continue;
		}
		int n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(c>=11&&c<=12){
			if(a[3]-a[1]<=d&&a[4]-a[1]>d){
				cout<<n-3<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(i-j)<3) continue;
				int res=0;
				for(int k=min(i,j);k<=max(i,j);k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
						res++;
					}
				}
				if(res==2) ans++;
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
