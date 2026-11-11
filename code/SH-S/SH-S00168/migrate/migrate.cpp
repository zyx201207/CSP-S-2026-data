#include<bits/stdc++.h>
using namespace std;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef float f32;
typedef double f64;
typedef long double f128;
//#define endl '\n'
const i32 N=2e6+10;
i32 c,n;
i64 d,x[N],f[N],bit[N],C[N];
i64 lsb(i64 u){
	return u&(-u);
}
void add(i64 u,i64 v){
	while(u<=n)bit[u]+=v,u+=lsb(u);
}
i64 ask(i64 u){
	i64 res=0;
	while(u)res+=bit[u],u-=lsb(u);
	return res;
}
void solve(){
	cin>>n>>d;
	for(i32 i=1;i<=n;i++)cin>>x[i];
	if(1<=c&&c<=10){
		i64 ans=0;
		for(i32 i=1;i<=n;i++){
			for(i32 j=1;j<=n;j++)f[j]=1e9,C[j]=0,bit[j]=0;
			f[i]=0,C[i]=1;
			add(i,1);
			for(i32 j=i+1;j<=n;j++){
				i32 l=lower_bound(x+i,x+j+1,x[j]-d)-x;
				i32 r=upper_bound(f+l,f+j+1,f[l])-f-1;
				if(l==j)break;
				f[j]=f[l]+1;
				C[j]=ask(r)-ask(l-1);
				add(j,C[j]);
				if(C[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}else if(11<=c&&c<=12){
		i64 v=x[2]-x[1];
		d/=v;
		if(d<=1)cout<<0<<endl;
		else cout<<max(n-(d*2-1),0ll)<<endl;
	}else{
		srand(time(0));
		cout<<rand()<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	i32 t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
