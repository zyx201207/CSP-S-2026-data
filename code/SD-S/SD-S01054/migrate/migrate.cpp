#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read();
const ll N=2e6+10,inf=0x3f3f3f3f3f3f3f3f;
ll c,T,a[N],n,d,dis[505][505]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(c<=6){
			memset(dis,0x3f,sizeof(dis));
			for(int l=1;l<=n;l++){
				dis[l][l]=0;int lst=l;
				for(int r=l+1;r<=n;r++){
					while(a[lst]+d<a[r])lst++;
//					cout<<lst<<"->"<<r<<'\n';
					dis[l][r]=dis[l][lst]+1;
				}
			}
			ll ans=0;
			for(int l=1;l<=n;l++){
				for(int r=l+1;r<=n;r++){
					ll mn=inf,mncnt=0;
					for(int k=l+1;k<r;k++){
						ll d=dis[l][k]+dis[k][r];
						if(d==dis[l][r])mncnt++;
					}if(mncnt==2){
						ans++; 
						
					}//if(n==7&&d==666666666666666663ll)cout<<l<<' '<<r<<' '<<dis[l][r]<<' '<<mncnt<<'\n'; 
				}
			}cout<<ans<<'\n';
		}
	} 
	return 0;
}
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/

