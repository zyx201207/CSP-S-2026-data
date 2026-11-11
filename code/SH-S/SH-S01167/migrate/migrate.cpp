#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int inf=1e9;
const int maxn=2e6+10;
int cid,T,n,d,x[maxn],f1[maxn],f2[maxn],nxt[maxn],id[maxn],sum0[maxn],sum1[maxn],ans=0;

inline int check(int a,int b,int c){
	if(nxt[b-1]<c) return 0;
	else if(nxt[b-2]<c) return 1;
	else return 2;
}
inline int get0(int a,int b,int c){
	int l=b+1,r=c-1;
	if(r<l) return 0;
	return max(0ll,r-nxt[b-1]);
}
inline int get1(int a,int b,int c){
	int l=b+1,r=c-1;
	if(r<l) return 0;
	l=max(l,nxt[b-2]+1);
	r=min(r,nxt[b-1]);
	return max(0ll,r-l+1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>cid>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		nxt[n]=n,nxt[n+1]=n+1;
		for(int i=n-1;i>=1;i--){
			nxt[i]=nxt[i+1];
			while(nxt[i]>i&&x[nxt[i]]-x[i]>d) nxt[i]--;
		}
		for(int i=1;i<=n;i++){
			if(nxt[i]==i) nxt[i]=n+1;
//			cout<<nxt[i]<<" ";
		}
//		cout<<"\n";
		for(int i=n;i>=1;i--){
			id[i]=id[nxt[i]]+1;
			if(nxt[nxt[i]]==n+1){
				f1[i]=f2[i]=n+1;
				continue;
			}
			int a=i,b=nxt[i],c=nxt[nxt[i]];
			int x=check(a,b,c);
			if(!x) f1[i]=f1[nxt[i]],f2[i]=f2[nxt[i]];
			else if(x==1) f1[i]=i,f2[i]=f1[nxt[i]];
			else f1[i]=f2[i]=i;
			int tmp0=get0(a,b,c),tmp1=get1(a,b,c);
			sum0[i]=tmp0+sum0[nxt[i]];
			sum1[i]=tmp1+sum1[nxt[i]];
//			cout<<i<<" "<<nxt[i]<<" "<<x<<" "<<f1[i]<<" "<<f2[i]<<" "<<get0(a,b,c)<<" "<<get1(a,b,c)<<" ";
			ans+=(sum1[i]-sum1[nxt[f1[i]]])+(sum0[nxt[f1[i]]]-sum0[nxt[f2[i]]]);
			ans+=(id[nxt[nxt[f1[i]]]]-id[nxt[nxt[f2[i]]]]);
//			cout<<i<<" "<<ans<<"\n";
			if(nxt[a-1]>=b-1){
				if(x==1) f1[i]=f2[i]=i;
				sum1[i]-=tmp1;
			}
		}
		cout<<ans<<"\n";
		for(int i=0;i<=n+1;i++){
			nxt[i]=x[i]=sum0[i]=sum1[i]=f1[i]=f2[i]=id[i]=0;
		}
	}
	return 0;
}

/*
let's see how the legal route might be?
let every step go to the longest legal place.

a -> b -> c -> d -> e

only when there only exist on place like a -> b-1 -> c is legal too.

let's see x0 -> x1 -> x2 -> x3 -> ...
let the first place d that allow x_{d-2} -> x_{d-1}-1 -> x_d call it f1_x0
the second place called f2_x0
in [x0,f1_x0),the a -> b-1 -> c must appear in the last segment.

[i,f1_i) : 1
[f1_i,f2_i) : 0

ok I get the prob!!
let's go to hub.

I AC it,now is 16:45 can I ak?
let's goooooo
*/
