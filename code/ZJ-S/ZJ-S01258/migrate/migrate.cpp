#include<bits/stdc++.h>
#define ll long long
using namespace std;
int _,T,n;
ll d,a[3000010],ans;
ll read(){
	char c=getchar();
	ll flag=1,res=0;
	while(c>'9'||c<'0'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
ll nxt(ll x){
	return upper_bound(a+1,a+n+1,x+d)-a-1;
}
ll lst(ll x){
	return lower_bound(a+1,a+n+1,x-d)-a;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	_=read(),T=read();
	while(T--){
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		a[0]=a[1]-1;
		if(n<=3){
			printf("0\n");
			continue;
		}
		if(_==11||_==12){
			d/=a[2]-a[1];
			if(d>1) printf("%lld\n",max(0ll,n-2ll*d+1ll));
			else printf("%lld\n",0);
			continue;
		}
		if(_==13||_==14){
			for(int i=1;i<=n;i++){
				int x=nxt(a[i]);
				if(x>=n) continue;
				int r=nxt(a[x-1]);
				int l=nxt(a[x-2]);
				ans+=max(0,r-max(l,i+2));
			}
			printf("%lld\n",ans);
			continue;
		}
		ll l=1,r=4;
		while(r<=n){
			if(r-l+1<=3){
				if(r==n) break;
				r++;
				continue;
			}
			if(nxt(a[nxt(a[l])])<r){
				l++;
				continue;
			}
//			cout<<l<<" "<<r<<" "<<nxt(a[l])<<" "<<nxt(a[nxt(a[l])])<<" ";
//			cout<<nxt(a[l])-lst(a[r])+1<<endl;
			if(nxt(a[l])-lst(a[r])+1==2){
				ll cnta=1,cntb=1;
				for(int x=l;x;x=lst(a[x])){
					if(!lst(a[x])||nxt(a[lst(a[x])])!=x) break;
					cnta++;
				}
				for(int x=r;x<=n;x=nxt(a[x])){
					if(nxt(a[x])>n||lst(a[nxt(a[x])])!=x) break;
					cntb++;
				}
				ans+=cnta*cntb;
				l++;
			}
			else if(nxt(a[l])-lst(a[r])+1>2){
				if(r==n) break;
				r++;
			}
			else l++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
