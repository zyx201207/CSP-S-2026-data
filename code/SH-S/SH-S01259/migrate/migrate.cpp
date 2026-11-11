#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,a[2000010],b[2000010],cd[2000010],f[5005][5005],g[5005][5005];
deque<pair<long long,long long> >Q;

void solve(){
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		while(!Q.empty()) Q.pop_back();
		f[i][i]=0;g[i][i]=1;
		for(int j=i+1;j<=n;j++) f[i][j]=1ll<<60;
		Q.push_back(make_pair(i,0));
		long long np=0,ng=1;
		for(int j=i+1;j<=n;j++){
			while((!Q.empty())&&a[j]-a[Q[0].first]>d){
				ng-=g[i][Q[0].first];
				np--;
				Q.pop_front();
			}
			if(Q.empty()) break;
			if(np<0){
				np=0,ng=g[i][Q[0].first];
				while(Q[np]!=Q.back()&&Q[np+1].second==Q[np].second) ng+=g[i][Q[++np].first];
			}
			f[i][j]=Q[np].second+1;
			g[i][j]=ng;
			//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<g[i][j]<<endl;
			if(ng==2) ans++;
			Q.push_back(make_pair(j,f[i][j]));
			if(f[i][j]==Q[np].second) np++,ng+=g[i][j];
		}
	}
	printf("%lld\n",ans);
}

void solve1(){
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),cd[i]=0;
	for(int i=n,p=n;i>1;i--){
		while(p>1&&a[i]-a[p-1]<=d) p--;
		b[i]=p;
		cd[b[i]]++;
	}
	for(int i=1,p=1;i<=n;i++){
		while(p<n&&a[p+1]-a[i]<=d) cd[b[++p]]--;
		if(p==n) break;
		ans+=cd[p-1];
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==13||c==14){
		while(t--) solve1();
		return 0;
	}
	while(t--) solve();
	return 0;
}
