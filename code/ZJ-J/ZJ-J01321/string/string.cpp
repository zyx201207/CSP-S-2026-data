#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{
	ll s,l,r;
	char c;
}a[200010];
ll n,m=1,ans;
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		a[i].s=read();
		cin>>a[i].c;
		a[i].l=m;
		m+=a[i].s;
		a[i].r=m-1;
//		cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].c<<"\n";
	}
	m--;
	for(ll i=1;i<=n;i++){
		if(a[i].l>m/2) break;
		ll l=0,r=m+1-a[i].l;
		if(a[i].r>m/2) l=m+1-m/2;
		else l=m+1-a[i].r;
		ll L=1,R=n,s=0;
		while(L<=R){
			ll mid=L+R>>1;
			if(a[mid].r>=l) s=mid,R=mid-1;
			else L=mid+1;
		}
//		cout<<l<<" "<<r<<" "<<s<<"\n";
		for(ll j=s;j<=n;j++){
			if(a[j].l>r) break;
			ll l1=0,r1=0;
			if(a[j].l<l) l1=l;
			else l1=a[j].l;
			if(a[j].r>r) r1=r;
			else r1=a[j].r;
			if(a[i].c!=a[j].c) ans+=r1-l1+1;
		}
	}
	printf("%lld",ans);
}
