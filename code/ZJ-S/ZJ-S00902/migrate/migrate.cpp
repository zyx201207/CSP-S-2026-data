#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--) 
#define pii pair<int,unsigned int>
#define fir first
#define sec second
const int N=2e6+7,inf=1e18;
inline int read(){
	int w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return w*f;
} 
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0'); 
}
int tid,T,n,d,a[N],f[N],g[N];
int dp1[N],dp2[N],cnt=0;
bool flag=0;
inline pii merge(pii X,pii Y){
	if(X.fir==Y.fir){
		return {X.fir,X.sec+Y.sec};
	}
	else return min(X,Y);
}
struct SGT{
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
	pii tr[N<<2];
	void pushup(int p){
		tr[p]=merge(tr[ls],tr[rs]);
	}
	void update(int p,int l,int r,int pos,pii v){
		if(l==r){
			tr[p]=v;
			return;
		}
		if(pos<=mid) update(ls,l,mid,pos,v);
		else update(rs,mid+1,r,pos,v);
		pushup(p);
	}
	pii query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr){
			return tr[p];
		}
		pii tmp={inf,0};
		if(ql<=mid) tmp=merge(tmp,query(ls,l,mid,ql,qr));
		if(qr>mid) tmp=merge(tmp,query(rs,mid+1,r,ql,qr));
		return tmp;
	}
}sgt;
void solve(int l,int r){
//	cout<<"l="<<l<<" r="<<r<<"\n";
//	if(l==2&&r==5) cout<<"l="<<l<<" r="<<r<<"\n";
	rep(i,l,r-1){
		if(a[i+1]-a[i]>d){
			flag=1;
			return;
		}
	}
	rep(i,l,r) dp1[i]=inf,dp2[i]=0;
//	rep(i,l,r) sgt.update(1,1,n,i,{inf,0});
	dp1[l]=0,dp2[l]=1;
	sgt.update(1,1,n,l,{0,1});
	rep(i,l+1,r){
		if(dp2[i]>2){
			flag=1;
			return;
		} 
//		per(j,i-1,l){
//			if(a[i]-a[j]>d) break;
////			cout<<"i="<<i<<" j="<<j<<"\n";
//			if(dp1[j]+1==dp1[i]){
//				dp2[i]+=dp2[j]; 
//			} 
//			else if(dp1[i]>dp1[j]+1){
//				dp1[i]=dp1[j]+1;
//				dp2[i]=dp2[j];
//			}
//		}
		int lpos=f[i];
		pii tmp=sgt.query(1,1,n,max(l,lpos),i-1);
		dp1[i]=tmp.fir+1,dp2[i]=tmp.sec;
		sgt.update(1,1,n,i,{dp1[i],dp2[i]});
	}
//	if(l==2&&r==5){
//		rep(i,l,r) cout<<dp1[i]<<" ";
//		cout<<"\n"; 
//		rep(i,l,r) cout<<dp2[i]<<" ";
//		cout<<"\n";		
//	}
	if(dp2[r]!=2) return;
	cnt++;
//	cout<<"ok!\n";
#undef ls
#undef rs
#undef mid
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
bool flgA=1,flgB=1;
void solveA(){
	int k=d/(a[2]-a[1]);
	if(k==0||k==1){
		cout<<0<<"\n";
		return;
	}
//	k++;
//	cout<<"k="<<k<<"\n";
	cnt=0;
	rep(len,k+1,n-1){
//		int t=len/k;
		if((len+k-1)/k==2&&len%k==k-1){
//			cout<<"len="<<len<<"\n";
			cnt+=n-len;
		}
	}
	cout<<cnt<<"\n";
}
int sp=0;
void YIOXII(){
	cnt=0;
	n=read(),d=read();
	rep(i,1,n) a[i]=read();
	flgA=flgB=1;
	flgB=0; 
	rep(i,1,n){
		int l=1,r=i,pos=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]-a[mid]<=d) pos=mid,r=mid-1;
			else l=mid+1;
		}
		f[i]=pos;
	} 
	rep(i,2,n){
		flgA&=(a[i]-a[i-1]==a[2]-a[1]); 
	}
	rep(i,1,n){
		if(a[n]-a[i]<=d&&a[i]-a[1]<=d){
			flgB=1;
			sp=i;
		}
	}
	if(flgA&&n>5000){
		solveA();
		return;
	}
//	rep(i,1,n) cout<<f[i]<<" ";
//	cout<<"\n";
	int cc=0;
	rep(l,1,n){
		flag=0;
		rep(r,l+1,n){
			solve(l,r);
			cc++;
			if(flag==1) break;
		}
	}
//	cerr<<"cc="<<cc<<"\n";
	cout<<cnt<<"\n";
}
/*
0 1
5 2
1 2 3 4 5
*/
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	tid=read(),T=read();
	while(T--){
		YIOXII();
	}
	return 0;
}
