#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int read(){
	register int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48),c=getchar();
	return res*f;
}
const int N=2e6+9,M=309;
int c,n;
ll d,a[N];
//int l[N],r[N],idx;
int f[M][M];
ll g[M][M];
void solve(){
	//	idx=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		int p=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
//		if(p-1<=i){
////			i++;
//			continue;
//		}
//		if(p-1!=i+1){
//			if(a[p+1]-a[i+1]>d){
////				i++;
//				continue;
//			}
//		}
//		int ri=upper_bound(a+1,a+1+n,a[p-1]+d)-a-1;
//		if(ri==p){
////			i++;
//			continue;
//		}
//		int res=0;
//		bool flag=0;
////		puts("823480923409823409809234");
//		for(int j=ri;j>p;j--){
//			if(a[j]-a[p-2]>d){
//				if(p+1!=j){
//					if(a[j-1]-a[p-1]<=d){
//						res=j;
//						flag=1;
//					}
//				}else{
//					res=j;
//					flag=1;
//				}
//			}
//		}
////		puts("823480923409823409809234");
//		if(flag){
//			l[++idx]=i;
//			r[idx]=res;
////			i=res;
//			//
//		}else{
////			i++;
//		}
//	}
//	cout<<idx<<'\n';
//	for(int i=1;i<=idx;i++){
//		cout<<l[i]<<' '<<r[i]<<'\n';
//	}
//	
//	ll ans=0,res1=0,res2=0;
//	res1=lower_bound(a+1,a+1+n,a[l[1]+1]-d)-a;
//	for(int i=1;i<idx;i++){
//		res2=lower_bound(a+1,a+1+n,a[l[i+1]+1]-d)-upper_bound(a+1,a+1+n,a[r[i]-1]+d)+1;
//		ans+=res1*res2;
////		cout<<res1<<' '<<res2<<'\n';
//		res1=res2;
//	}
//	res2=n-(upper_bound(a+1,a+1+n,a[r[idx]]+d)-a)+2;
//	ans+=res1*res2;
////	cout<<res1<<' '<<res2<<'\n';
//	cout<<ans<<'\n';

	//	ll ans=0;
//	for(int i=1;i<=n;i++){
//		int id=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
//		ans+=max(0ll,upper_bound(a+1,a+1+n,a[id-1]+d)-a-1-(upper_bound(a+1,a+1+n,a[id-2]+d)-a-1));
//	}
//	cout<<ans<<'\n';
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=INF;
			g[i][j]=0;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(a[j]-a[i]<=d){
				f[i][j]=1;
				g[i][j]=1;
			}else{
				for(int k=i+1;k<=j-1;k++){
					if(a[k]-a[i]<=d){
						if(f[i][j]>1+f[k][j]){
							f[i][j]=f[k][j]+1;
							g[i][j]=g[k][j];
						}else if(f[i][j]==f[k][j]+1){
							g[i][j]+=g[k][j];
						}
					}else break;
				}
			}
		}
		
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	cin>>n>>d;
	int res;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[1]<=d){
			res=i;
		}
	}
	if(res<=2){
		cout<<0<<'\n';
		return ;
	}
	int num=res*2-2;
	if(n-num+1<=0||n-num+1>n){
		cout<<0<<'\n';
	}else{
		cout<<n-num+1<<'\n';
	}
}
void solve3(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int id=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		ans+=max(0ll,upper_bound(a+1,a+1+n,a[id-1]+d)-a-1-(upper_bound(a+1,a+1+n,a[id-2]+d)-a-1));
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>c>>T;
	if(c<=10){
		while(T--){
			solve1();
		}
		return 0;
	}
	if(c==11||c==12){
		while(T--) solve2();
		return 0;
	}
	while(T--) solve3();
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

1 1 0 0 0 0 0
1 1 1 1 0 0 0
0 1 1 1 1 1 0
0 1 1 1 1 1 0
0 0 1 1 1 1 1
0 0 1 1 1 1 1
0 0 0 0 1 1 1

0 1 2 2 3 3 4
0 0 1 1 2 2 3
0 0 0 1 1 1 2
0 0 0 0 1 1 2
0 0 0 0 0 1 1
0 0 0 0 0 0 1
0 0 0 0 0 0 0

0 1 1 1 4 4 20
0 0 1 1 2 2 8
0 0 0 1 1 1 2
0 0 0 0 1 1 2
0 0 0 0 0 1 1
0 0 0 0 0 0 1
0 0 0 0 0 0 0

*/
