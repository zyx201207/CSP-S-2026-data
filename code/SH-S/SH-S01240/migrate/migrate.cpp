#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read(){
	TN rst=0;bool mns=0;
	char ch=getchar();
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')mns=1,ch=getchar();
	while(isdigit(ch))rst=rst*10+(ch^48),ch=getchar();
	return mns?-rst:rst;
}
int n,xL[2000005],xR[2000005];
long long d,x[2000005],fl[2000005],fr[2000005]/*,gl[2000005],gr[2000005]*/;
/*
fl往左跳(至少1步)，第一步不能到右边一位能到的地方 
gl往左跳 
*/
inline void main_solve(){
	n=read<int>();
	d=read<long long>();
	for(int i=1;i<=n;++i)x[i]=read<long long>();
	x[0]=x[1]-d-1,x[n+1]=x[n]+d+1;
	//cerr<<"C";
	fill(xL,xL+n+2,0);
	//cerr<<"D";
	fill(xR,xR+n+2,0);
//	fill(gl,gl+n+2,0);
//	fill(gr,gr+n+2,0);
	fill(fl,fl+n+2,0);
	fill(fr,fr+n+2,0);
	for(int i=1;i<=n;++i){
		xL[i]=xL[i-1];
		while(x[xL[i]]<x[i]-d)++xL[i];
		//cerr<<"xL "<<i<<' '<<xL[i]<<'\n';
	}//cerr<<"!";
	xL[n+1]=xR[n+1]=n+1;
	for(int i=n;i;--i){
		xR[i]=xR[i+1];
		while(x[xR[i]]>x[i]+d)--xR[i];
	}
	for(int i=1;i<=n;++i){
		int l=xL[i],r=xL[i+1]-1;
		//gl[i]=i-l+1+fl[l];
		if(l>r)continue;
		fl[i]=r-l+1+fl[l];
	//	gl[i]=fl[i]+1;
	//	cerr<<"fgl "<<i<<' '<<l<<' '<<r<<' '<<fl[i]<<' '<<gl[i]<<'\n';
	}
	//cerr<<"OK";
	for(int i=n;i;--i){
		int l=xR[i-1]+1,r=xR[i];
		//gr[i]=r-i+1+fr[r];
		if(l>r)continue;
		fr[i]=r-l+1+fr[r];
	//	gr[i]=fr[i]+1;
	//	cerr<<"fgr "<<i<<' '<<l<<' '<<r<<' '<<fr[i]<<' '<<gr[i]<<'\n';
	}
	//for(int i=1;i<=n;++i)gl[i]+=gl[i-1],gr[i]+=gr[i-1];
	long long ans=0;
	for(int i=2;i+1<n;++i){
		//if(xL[i+1]>=i||xR[i]<=i+1)continue;
		//xL[i+1]~xL[i+2]-1, xR[i-1]+1~xR[i]
		int r=min(xL[i+2]-1,i-1),l=xL[i+1],R=xR[i],L=max(i+2,xR[i-1]+1);
		if(l>r||L>R)continue;
		long long Al=0,Ar=0;
		if(R==xR[i+1])Ar=fr[R];
		if(l==xL[i])Al=fl[l];
		ans+=(r-l+1+Al)*(R-L+1+Ar);
		//cerr<<"lmt: "<<xL[i+1]<<' '<<xL[i+2]-1<<' '<<xR[i-1]+1<<' '<<xR[i]<<'\n';
		//cerr<<"lmt "<<i<<' '<<l<<' '<<r<<' '<<L<<' '<<R<<'\n';
		//cerr<<"ans "<<i<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	read<int>();
	int nTest=read<int>();
	while(nTest--)main_solve();
	return 0;
}
