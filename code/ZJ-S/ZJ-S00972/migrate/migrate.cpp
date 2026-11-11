#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define gc getchar
typedef long long ll;
int n,nxt[N],lst[N];ll d,a[N],sl[N],sr[N],ans;bool fl[N],fr[N];
inline int read(){
	int k=0,f=1,c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())k=k*10+(c^48);
	return k*f;
}
inline ll Read(){
	ll k=0;int f=1,c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())k=k*10+(c^48);
	return k*f;
}
inline void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);putchar('0'+x%10);
}
inline bool check(int l,int r){
	vector<int>x,y;int ql=l,qr=r;
	while(ql<r){if(ql==nxt[ql])return false;ql=min(nxt[ql],r);if(ql!=r)x.push_back(ql);}
	while(qr>l){if(qr==lst[qr])return false;qr=max(lst[qr],l);if(qr!=l)y.push_back(qr);}
	reverse(y.begin(),y.end());int flag=2;
	for(int i=0;i<(int)x.size();i++){
		if(x[i]!=y[i]){
			if(abs(x[i]-y[i])==1)flag--;
			else flag=0;
		}
	}
	if(flag==1)return true;
	return false;
}
inline void solve(){
	n=read();d=Read();ans=0;
	for(int i=1;i<=n;i++)sl[i]=sr[i]=0,fl[i]=fr[i]=0;
	for(int i=1;i<=n;i++)nxt[i]=lst[i]=0;
	for(int i=1;i<=n;i++)a[i]=Read();
	for(int i=1,j=1;i<=n;i++){
		while(j<n && a[j+1]-a[i]<=d)j++;
		nxt[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j && a[i]-a[j-1]<=d)j--;
		lst[i]=j;
	}
	for(int i=1;i<=n;i++)if(lst[nxt[i]]==i)fr[i]=1;
	for(int i=1;i<=n;i++)if(nxt[lst[i]]==i)fl[i]=1;
	for(int i=1;i<=n;i++){if(fl[i])sl[i]=sl[lst[i]]+1;else sl[i]=1;}
	for(int i=n;i>=1;i--){if(fr[i])sr[i]=sr[nxt[i]]+1;else sr[i]=1;}
//	for(int i=1;i<=n;i++)write(nxt[i]),putchar(' ');putchar('\n');
//	for(int i=1;i<=n;i++)write(lst[i]),putchar(' ');putchar('\n');
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(check(i,j))ans++;
		}
	}
//	for(int i=1;i<=n;i++){
//		if(nxt[i]<=i+1)continue;
//		if(nxt[nxt[i]-1]<=(nxt[i]-1))continue;
//		if(nxt[nxt[i]]<=nxt[i])continue;
//		int t=nxt[nxt[i]-1];
//		if(nxt[i]>i+2 && t<=nxt[nxt[i]-2])continue;
//		if(t==nxt[nxt[i]])ans+=sl[i]*sr[t];
//		else ans+=sl[i];
//		write(i);putchar(' ');write(t);putchar('\n');
//	}
	write(ans);putchar('\n');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _,T;_=read();T=read();while(T--)solve();
	return 0;
}