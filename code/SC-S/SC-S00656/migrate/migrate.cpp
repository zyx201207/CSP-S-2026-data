#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;long long d;
long long x[N],lst[N],lst2[N];
long long read(){
	char c;int k,f;
	c=getchar();
	if(c<'0'||c>'9'){
		c=getchar();
		f=-1;
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			n=read();d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
			long long dd=x[2]-x[1];
			if(dd<d&&dd<2*d)cout<<n-3<<endl;
			else cout<<0<<endl;
		}
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans=0;
		for(int i=4;i<=n;i++){
			if(x[i-1]+d<x[i]&&x[i-2]+d<x[i])continue;
			if(x[i-3]+2*d<x[i]||x[i-3]+d>=x[i])continue;
			if(x[i-3]+d<x[i-1]||x[i-3]+d<x[i-2])continue;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}