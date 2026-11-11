#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=s;i<=e;++i)
#define ROF(i,e,s) for(int i=e;i>=s;--i)
#define LL long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while(s<'0'||s>'9'){ if(s=='-') f=-1;s=getchar(); }
	while(s>='0'&&s<='9'){ x=x*10+(s-'0'); s=getchar(); }
	return x*f;
}
int n,cnt,ans,nowp;
LL a[N],m,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	nowp=n;
	x=a[nowp]-a[nowp-1];
	ROF(i,n,1){
//		ans=max(ans,cnt);
		if(a[nowp]-a[i]<=m){
			cnt++;
			m=m-(a[nowp]-a[i]);
		}
		else{
			while(a[nowp]-a[i]>m){
				m=m+x*(cnt-1);
				nowp--;cnt--;
				x=a[nowp]-a[nowp-1];
			}
			cnt++;
			m=m-(a[nowp]-a[i]);
			x=a[nowp]-a[nowp-1];
		}
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}

