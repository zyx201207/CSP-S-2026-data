#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int N=5e5+10;
inline int read(){
	int f=1,s=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return f*s;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	string s="";
	while(x){
		s+=(x%10)+'0';
		x/=10;
	}
	if(s==""){
		putchar('0');
	}
	per(i,s.size()-1,0){
		putchar(s[i]);
	}
}
int a[N];
bool cmp(int x,int y){
	return x<y;
}
void solve(){
	int n=read(),m=read();
	rep(i,1,n){
		a[i]=read();
	}
	int l=1;
	int sum=0,ans=1;
	sort(a+1,a+n+1,cmp);
	rep(r,2,n){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	write(ans);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
//	_=read();
	while(_--){
		solve();
	}
	return 0;
}
