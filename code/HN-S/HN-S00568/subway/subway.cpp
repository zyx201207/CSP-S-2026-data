#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
long long c,n,m,d,q,w[500005];
long long x[505][50005];
long long ru,rv,ans=0;
long long js(long long xl,long long kt,long long jw){
	long long w=0;
	for(int i=kt;i<=jw;i++){
		w+=x[xl][i];
	}
	return w;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		long long tt=read();
		while(tt--){
			long long t1,t2;
			t1=read();
			t2=read();
			x[i][t1]=t2;
		}
	}
	while(q--){
		ans=1e18;
		ru=read();
		rv=read();
		if(ru>rv)swap(ru,rv);
		for(int i=1;i<=n;i++){
			if(x[i][ru]!=0&&x[i][rv]!=0){
				int ww=js(i,ru,rv);
				ans=min(ans,ww+w[ru]+w[rv]);
			}
		}
		if(ans!=1e18)cout<<ans<<endl;
		else cout<<(w[ru]+w[rv])*2+w[ru]+w[rv+1]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
