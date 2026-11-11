#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
const int M = 5000+5;
int c,t,n,d,x[N],cnt[M],minn[M],k,ans;
inline void solve1(){
	while(t--){
		cin>>n>>d; k=ans=0;
		for(int i=1;i<=n;++i) cin>>x[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		int tmp=x[2]-x[1];
		while(tmp<=d) k++,tmp+=x[2]-x[1];
		if(k<=1){
			cout<<"0\n";
			continue;
		}
		for(int i=1,l,r;i<=n;++i){
			l=k+i+k-2,r=min(2*k+i,n+1);
			if(l>=r) continue;
			ans+=r-l-1; 
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		solve1();
		return 0;
	}
	while(t--){
		cin>>n>>d; ans=0;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i){
			memset(cnt,0,sizeof(cnt)); 
			memset(minn,0,sizeof(minn));
			for(int j=i;j<=n;++j){
				if(x[j]-x[i]<=d){
					cnt[j]=1;
					minn[j]=1;
					continue;
				}
				int k=j;
				while(x[j]-x[k]<=d) k--;
				minn[j]=minn[k+1]+1;
				for(int x=k+1;x<=j;++x){
					if(minn[x]+1==minn[j])
						cnt[j]++;
				}
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
