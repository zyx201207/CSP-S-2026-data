#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],minn=1e18,maxn=-1e18,ans,qz[500010],cha;
bool flag1=1,flag2=1;
ll read(){
	ll f=1,cnt=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		cnt=cnt*10+ch-'0';
		ch=getchar();
	}
	return f*cnt;
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=i) flag1=0;
	}
	sort(a+1,a+1+n,cmp);
	for(ll i=2;i<=n;i++){
		if(i>=3 && a[i]-a[i-1]!=cha) flag2=0;
		if(i==2) cha=a[i]-a[i-1] ;
	}
	if(flag1){
		cout<<min((ll)(sqrt(2*m+3)),n);
		return 0;
	}
	if(flag2){
		cha=abs(cha);
//		cout<<sqrt(double(8*m+cha)/double(4*cha))<<'\n';
		cout<<(ll)((2*(ll)sqrt((8*m+cha)/(4*cha))+3)/2);
		return 0;
	}
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<=r){
			ll mid=(l+r)/2;
			if(qz[mid]-qz[i-1]+m>=a[i]*(mid-i+1)) l=mid+1;
			else r=mid-1;
		}
		while(qz[l]-qz[i-1]+m<a[i]*(l-i+1) && l>=i) l--;
		while(qz[l+1]-qz[i-1]+m>=a[i]*(l-i+2) && l<=n) l++;
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

4 3
1 3 5 7
*/
