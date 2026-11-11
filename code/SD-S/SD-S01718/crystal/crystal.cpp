#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=1,f=0;char ch=getchar();
    while(ch>'9'||ch<'0'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll n,m;
ll a[500005],b[500005],c[500005],d[500005];
ll find(int l,int r,int z){
	int mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(0-m>=c[mid]+b[z]*(z-mid))l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		n=read(),m=read();
	ll isa=1,isb=1,s=0;
	memset(b,0,sizeof b);
	memset(d,0,sizeof d);
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=i)isa=0;
		c[i+1]=c[i]+i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==2){
			s=a[i]-a[i-1];
		}
		else if(i!=1&&s!=a[i]-a[i-1])isb=0;
	}
	if(n==1){
		cout<<1;return 0;
	}
	ll ans=1,l=0,now;
	if(n<=5000){
		for(int i=2;i<=n;i++){
			l=m,now=1;
			for(int j=i-1;j>=1;j--){
				l-=a[i]-a[j];
				if(l<0)break;
				now++;
			}
			ans=max(ans,now);
		}
		cout<<ans;
		return 0;
	}
	if(isa==1){
		for(int i=2;i<=n+1;i++){
			if(m<c[i]){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
//	cout<<isb;
	if(isb==1){
		for(int i=1;i<=n;i++){
			c[i+1]=c[i]+s*i;
			//cout<<c[i+1]<<' ';
		}
		for(int i=2;i<=n+1;i++){
			if(m<c[i]){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0; 
	}
	return 0;
}
//rp++ afo 
//60+ v
//30+ = 
//6 x 
//in memory of wangchen101
//-100000$ 
//45拿下，继续A!
//A拿下，继续B！！
//B拿下，冲100！！
//已有思路：前缀和+二分。开写 
 // 5 5
 //1 2 4 8 9
 //仍有1h30min。 
 //测样例。 
 //失败。75走人。 
 //md双指针最后30min看出来了神泵的住 
