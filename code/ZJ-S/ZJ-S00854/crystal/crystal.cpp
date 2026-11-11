#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define N 500010
//#define inf 
//#define mod 
using namespace std;
ll read(){
	int f=0;
	ll ans=0;
	char c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10ll+c-'0';
		c=getchar();
	}
	if(f){
		ans*=-1;
	}
	return ans;
}
int n,l,r,ans;
ll m,a[N],s[N];
bool check(int x){
	ll v,c;
	for(int i=x;i<=n;i++){
		v=s[i]-s[i-x];
		c=a[i]*x-v;
		//printf("%lld %lld\n",v,c);
		if(c<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		//printf("%d\n",mid);
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/