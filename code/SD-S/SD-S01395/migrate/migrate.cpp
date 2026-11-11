#include<iostream>
#include<cstdio>
using namespace std;
using ll=long long;
const int N=2e6+5;
int ID,T,n;ll d,a[N];
ll f[N],cnt[N];int g[N];
int Q[N],L,R;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	if(ID==11||ID==12){
		L=0,R=-1;Q[++R]=1;
		for(int j=0;j<=n;j++)f[j]=g[j]=cnt[j]=0;
		cnt[0]=1,f[1]=1;
		for(int j=2;j<=n;j++){
			while(L<=R&&a[j]-a[Q[L]]>d)cnt[g[Q[L]]]-=f[Q[L]],L++;
			if(L>R)break;
			g[j]=g[Q[L]]+1,f[j]=cnt[g[Q[L]]],cnt[g[j]]+=f[j],Q[++R]=j;
			if(f[j]==2)ans+=n-j+1;
		}
		return cout<<ans<<'\n',void();
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			L=0,R=-1;Q[++R]=i;
			for(int j=0;j<=n;j++)f[j]=g[j]=cnt[j]=0;
			cnt[0]=1,f[i]=1;
			for(int j=i+1;j<=n;j++){
				while(L<=R&&a[j]-a[Q[L]]>d)cnt[g[Q[L]]]-=f[Q[L]],L++;
				if(L>R)break;
				g[j]=g[Q[L]]+1,f[j]=cnt[g[Q[L]]],cnt[g[j]]+=f[j],Q[++R]=j;
	//			cout<<i<<' '<<j<<' '<<g[j]<<' '<<f[j]<<'\n';
				if(f[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';	
		return ;
	}
	for(int p=1;p<=n;p++)
		if(a[p]-a[1]<=d&&a[n]-a[p]<=d){
			for(int i=0;i<=n;i++)cnt[i]=0;
			L=0,R=-1;
			for(int i=n;i>=p;i--)Q[++R]=i;
			for(int i=p-1;i;i--){
				while(L<=R&&a[Q[L]]-a[i]>d)L++;
				if(R-L+1>=2)cnt[Q[L]]++;
				Q[++R]=i;
			}
			L=0,R=-1;
			for(int i=1;i<=p;i++)Q[++R]=i;
			for(int i=p+1;i<=n;i++){
				while(L<=R&&a[i]-a[Q[L]]>d)L++;
				if(R-L+1>=2)ans+=cnt[Q[L+1]];
				Q[++R]=i;
			}
			cout<<ans<<'\n';
//			cout<<ans<<' ';
//			ans=0;break;
			return ;
		}
	for(int i=1;i<=n;i++){
		L=0,R=-1;Q[++R]=i;
		for(int j=0;j<=n;j++)f[j]=g[j]=cnt[j]=0;
		cnt[0]=1,f[i]=1;
		for(int j=i+1;j<=n;j++){
			while(L<=R&&a[j]-a[Q[L]]>d)cnt[g[Q[L]]]-=f[Q[L]],L++;
			if(L>R)break;
			g[j]=g[Q[L]]+1,f[j]=cnt[g[Q[L]]],cnt[g[j]]+=f[j],Q[++R]=j;
	//		cout<<i<<' '<<j<<' '<<g[j]<<' '<<f[j]<<'\n';
			if(f[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ID>>T;while(T--)solve();
	return 0;
}
//last remote

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
6 6
-5 -3 -1 1 3 5

0 6
10 31746031746031745
-1000000000000000000 -777777777777777785 -555555555555555570 -333333333333333355 -111111111111111140 111111111111111075 333333333333333290 555555555555555505 777777777777777720 999999999999999935
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987

*/
