#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[2000010],pre,s,ans,L,R;
void build(long long w,long long l,long long r){
	if(l==r){
		t[w]=a[l];
		return;
	}
	long long mid=(l+r)/2;
	build(w*2,l,mid);
	build(w*2+1,mid+1,r);
	t[w]=t[w*2]+t[w*2+1];
}
long long query(long long w,long long l,long long r){
	if(L<=l&&r<=R){
		return t[w];
	}
	long long mid=(l+r)/2,res=0;
	if(mid>=L) res+=query(w*2,l,mid);
	if(mid<R) res+=query(w*2+1,mid+1,r);
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i;i--){
		a[i]-=a[i-1];
	//	cout<<a[i]<<' ';
	}
	a[1]=0;
	build(1,1,n);
	for(int last=1;last<=n;last++){
		s+=(last-pre)*a[last];
		while(s>m){
			L=pre+1;
			R=last;
			s-=query(1,1,n);
			pre++;
		}
		ans=max(ans,last-pre+1);
	}
	cout<<ans;
	return 0;
}

