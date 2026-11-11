#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
//#define ull unsigned long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,a[N];
int sum[N];
inline bool checkA(){
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]) return false;
	}
	return true;
}
inline bool checkB(){
	int d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d) return false;
	}
	return true;
}
void solve(){//45
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int len=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int sz=r-l+1;
			int nw=sum[r]-sum[l-1];
			int nd=a[r]*sz-nw;
			if(nd>m) continue;
			else len=max(len,sz);
//			cout<<"l: "<<l<<" r: "<<r<<" len: "<<len<<"\n";
		}
	}
	cout<<len;
}
void sol(){
	//he bing guo zi?
//	map<int,int> mp;
//	priority_queue<pii> q;
//	int cnt=1;
//	for(int i=2;i<=n+1;i++){
//		if(a[i]!=a[i-1]) q.push({a[i-1],cnt}),cnt=1,mp[a[i-1]]=cnt;
//		else cnt++;
//	}
////	while(!q.empty()){int u=q.top().fir,v=q.top().sec;q.pop();cout<<u<<" "<<v<<"\n";}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int len=0;
	for(int l=1;l<=n;l++){
		for(int r=len+l-1;r<=n;r++){
			int sz=r-l+1;
			int nw=sum[r]-sum[l-1];
			int nd=a[r]*sz-nw;
			if(nd>m) break;
			else len=max(len,sz);
//			cout<<"l: "<<l<<" r: "<<r<<" len: "<<len<<"\n";
		}
	}
	cout<<len;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(checkA()){//15
		int k=m%n;
		if(k==0) cout<<n;
		else cout<<n-1;
		return 0;
	}
	if(checkB()){//15
		int d=a[2]-a[1],ans=0,tot=1,sum=0;
		while(ans<=m){
			sum+=tot;
			ans=sum*d;
			if(ans<=m) tot++;
		}
		cout<<tot;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=5000) solve();
	else sol();
//	cout<<"\n";
	return 0;
}
/*
crystal
*/
