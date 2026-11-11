#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 yellow1
#define ull unsigned long long
#define rank jkflsfasf
#define time fjklsaflsdfj
inline ll rd(){
	ll k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
char s[200007];
ll n,p[200007],sum[200007],l,r,fl,fr,ans=0;
void func(ll left,ll right,ll fl,ll fr){
	//cout<<left<<' '<<right<<' '<<fl<<' '<<fr<<'\n';
	if(fl==0&&fr==n+1) return;
	int k1=left-sum[fl-1],k2=sum[fr]-right+1;
	if(s[fl]!=s[fr]) ans+=min(k1,k2);
	if(k1==k2) func(left-k1,right+k2,fl-1,fr+1);
	else if(k1<k2) func(left-k1,right+k1,fl-1,fr);
	else func(left-k2,right+k2,fl,fr+1);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++){
		p[i]=rd();
		sum[i]=sum[i-1]+p[i];
		s[i]=getchar();
	}
	l=(sum[n]+1)/2;r=sum[n]/2+1;
	for(int i=1;i<=n;i++){
		if(sum[i]>=l&&fl==0) fl=i;
		if(sum[i]>=r&&fr==0) fr=i; 
	}
	//cout<<l<<' '<<r<<' '<<fl<<' '<<fr<<'\n';
	func(l,r,fl,fr);
	cout<<ans;
	return 0;
}

