#include<bits/stdc++.h>
#define lll long long
using namespace std;
lll read(){
	char c=getchar();
	lll s=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') s=(s<<3)+(s<<1)+c-'0',c=getchar();
	return s*f;
}
int c,T,n,ll,rr,l[2000010],r[2000010],l2[2000010],r2[2000010],w;
lll d,a[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while(T--){
		n=read();
		d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		ll=1,rr=n;
		for(int i=1;i<=n;i++){
			while(a[i]-a[ll]>d) ll++;
			l[i]=ll;
		}
		for(int i=n;i>=1;i--){
			while(a[rr]-a[i]>d) rr--;
			r[i]=rr;
		}
		memset(l2,0,sizeof(l2));
		memset(r2,0,sizeof(r2));
		for(int i=n;i>=1;i--){
			w=lower_bound(l+1,l+1+n,r[i])-l;
			if(w<=n&&l[w]==r[i]) r2[i]=r2[r[i]]+1;
		}
		for(int i=1;i<=n;i++){
			w=lower_bound(r+1,r+1+n,l[i])-r;
			if(l[w]==r[i]) l2[i]=l2[l[i]]+1;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			w=lower_bound(l+1,l+1+n,r[i]-1)-l;
			if(l[w]==r[i]-1&&r[i]!=i&&l[w]!=w&&w<=n) ans+=(r2[w]+1)*(l2[i]+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
