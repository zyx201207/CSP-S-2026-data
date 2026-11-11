#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[4000000];
long long v[4000000];
long long C;
vector<long long>E;
long long read(){
	char c;
	long long f=1,cur=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		cur=cur*10+(c^48);
		c=getchar();
	}
	return cur*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	c=read();
	t=read();
	while(t--){
		long long ans=0;
		n=read();
		d=read();
		for(long long i=1;i<=n;i++) x[i]=read();
		long long val=x[2]-x[1];
		bool f=0;
		for(long long i=2;i<=n;i++){
			if(x[i]-x[i-1]!=val) f=1;
		}
		if(!f){
			long long Bri=d/val;
			if(Bri<=1){
				cout<<0<<endl;
				continue;
			}
			long long kk=Bri*2-1;
			if(n-kk<0) cout<<0<<endl;
			else cout<<n-kk<<endl;
		}
		if(!f) continue;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) break;
				bool f=0;
				C=0,E.clear();
				E.push_back(i);
				long long now=i;
				for(long long k=i;k<=j;k++){
					if(x[k+1]-x[now]>d||k==j) E.push_back(k),now=k,C++;
				}
				long long Cnt=0;
				for(long long k=1;k<E.size()-1;k++){
					for(long long l=E[k]-1;l>=i;l--){
						if(x[l]-x[E[k-1]]<=d&&x[E[k+1]]-x[l]<=d){
							Cnt++;
							if(Cnt>1) f=1;
						}
						if(f) break;
					}
					if(f) break;
				}
				if(Cnt==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
