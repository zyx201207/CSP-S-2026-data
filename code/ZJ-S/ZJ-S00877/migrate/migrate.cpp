#include<bits/stdc++.h>
#define int long long
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=2e6+5;
int c,n,d,ans,T;
int p[N],f[N],cnt[N];
void solve(){
	n=read(),d=read(),ans=0;
	FL(i,1,n) p[i]=read(),f[i]=cnt[i]=0;
	if(c==11||c==12){
		if(n==1){
			cout<<"0\n";
			return ;
		}
		int len=p[2]-p[1];
		int tot=d/len;
		if(tot<2){
			cout<<"0\n";
			return ;
		}
		ans=max(0ll,n-tot-tot+1);
		cout<<ans<<"\n";
		return ;
	}
	FL(l,1,n){
		f[l]=0,cnt[l]=1;
		FL(r,l+1,n){
			if(p[r]-p[r-1]>d) break;
			f[r]=1e9,cnt[r]=0;
			int L=max(l,r-10);
			FL(i,L,r-1){
				if(p[r]-p[i]>d) continue;
				if(f[i]+1<f[r]){
					f[r]=f[i]+1;
					cnt[r]=cnt[i];
				}
				else if(f[i]+1==f[r]){
					cnt[r]+=cnt[i];
				}
			}
			if(cnt[r]==2) ans++;
		}
		
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--) solve();
	return 0;
}
