#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const long long inf=3e18;
long long read(){
	long long t=0,f=1;
	char g=getchar();
	while((g<'0' || g>'9') && g!=EOF){
		if(g=='-') f=-f;
		g=getchar();
	}
	while(g>='0' && g<='9' && g!=EOF){
		t=t*10+g-'0';
		g=getchar();
	}
	return t*f;
}
int T,c;
int n;
long long a[N+5],d;
bool checkA(){
	long long c=a[2]-a[1];
	for(int i=3;i<=n;++i)
		if(a[i]-a[i-1]!=c) return false;
	return true;
}
long long getans(int now,int y,long long w){
	if(now==y) return w;
	if(a[now+1]-a[now]>d) return inf;
	int idx=upper_bound(a+now+1,a+y+1,a[now]+d)-a-1;
	return getans(idx,y,w+1);
}
long long check(int now,int y,long long base,long long w){
	if(now==y && w==base) return 1;
	long long res=0;
	for(int i=now+1;i<=y;++i){
		if(a[i]-a[now]>d) break;
		res+=check(i,y,base,w+1);
	}
	return res;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		if(n<=2){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;++i) a[i]=read();
//		long long gc=a[2]-a[1];
//		if(checkA()){
//			if(2*gc<=d) cout<<(n-2)*2<<"\n";
//			else cout<<0<<"\n";
//			continue;
//		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+2;j<=n;++j){
				long long dis=getans(i,j,0LL);
				if(check(i,j,dis,0LL)==2LL) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}