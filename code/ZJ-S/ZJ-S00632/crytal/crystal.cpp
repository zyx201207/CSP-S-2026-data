#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e12+5;
int n,m,a[500005],t[2000005],s[500005],ans=1,hl,hr,md;
void bd(int p,int l,int r){
	if(l==r){
		t[p]=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	bd(p*2,l,mid);
	bd(p*2+1,mid+1,r);
	if(t[p*2]>=t[p*2+1]) t[p]=t[p*2];
	else t[p]=t[p*2+1];
	return;
}
int qu(int p,int l,int r,int tl,int tr){
	if(l>tr||tl>r) return -inf;
	if(tl<=l&&r<=tr) return t[p];
	int mid=l+(r-l)/2;
	int t1=qu(p*2,l,mid,tl,tr);
	int t2=qu(p*2+1,mid+1,r,tl,tr);
	if(t1>=t2) return t1;
	else return t2;
}
bool ch(int k){
	//cout<<"len="<<k<<"\n";
	for(int i=1;i<=n-k+1;i++){
		//cout<<qu(1,1,n,i,i+k-1)*k-(s[i+k-1]-s[i-1])<<"\n";
		if(qu(1,1,n,i,i+k-1)*k-(s[i+k-1]-s[i-1])<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	bd(1,1,n);
	hl=0,hr=n;
	while(hl<=hr){
		md=hl+(hr-hl)/2;
		if(ch(md)){
			ans=md;
			hl=md+1;
		}else{
			hr=md-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
