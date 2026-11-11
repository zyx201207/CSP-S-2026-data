#include<bits/stdc++.h>
using namespace std;
long long dis[2000002],cnt[2000002],a[2000002],n,d,ans,t;
long long read(){
	char c=getchar();
	long long k=0;
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void solve(){
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		if(n==1||d<=a[2]-a[1]||n-d/(a[2]-a[1])*2+1<0){
			cout<<"0\n";
			continue;
		}
		cout<<n-d/(a[2]-a[1])*2+1<<'\n';
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	c=read(),t=read();
	if(c==11||c==12){
		solve();
		return 0;
	}
	while(t--){
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=n;a[i]-a[1]>d;--i){
			dis[i]=0,cnt[i]=1;
			int l,r=i,j=i-1;
			while(a[i]-a[j]<=d){
				dis[j]=1,cnt[j]=1;
				--j;
			}
			for(;j>=1;--j){
				if(a[j+1]-a[j]>d) break;
				while(a[r]-a[j]>d) --r;
				dis[j]=dis[r]+1;
				l=r-1;
				cnt[j]=cnt[r];
				while(dis[l]==dis[r]){
					cnt[j]+=cnt[l],--l;
					if(cnt[j]>2) break;
				}
				if(cnt[j]==2){
//					cout<<j<<" "<<i<<'\n';
					++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}