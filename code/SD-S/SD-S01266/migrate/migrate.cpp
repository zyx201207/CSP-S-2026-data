#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long x[N];
int l[N],r[N],idx[N],mn[N],cnt[2][N],qwq[2][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i],mn[i] = idx[i] = 0;
		l[1] = 1;
		for(int i=2;i<=n;i++){
			l[i] = l[i-1];
			while(x[i]-x[l[i]]>d) l[i]++;
		}
		r[n] = mn[n] = n;
		for(int i=n-1;i>=1;i--){
			r[i] = r[i+1];
			while(x[r[i]]-x[i]>d) r[i]--;
			mn[r[i]] = i;
		}
		cnt[0][1] = cnt[1][1] = 1,l[n+1] = n+1;
		for(int i=2;i<=n;i++){
			if(l[i]==i) cnt[0][i] = 1;
			else cnt[0][i] = i-l[i]+cnt[1][l[i]];
			if(l[i+1]==l[i]) cnt[1][i] = 1;
			else cnt[1][i] = cnt[0][i]-max(0,i-l[i+1]);
		}
		qwq[0][n] = qwq[1][n] = 1,r[0] = 0;
		for(int i=n-1;i>=1;i--){
			if(r[i]==i) qwq[0][i] = 1;
			else qwq[0][i] = r[i]-i+qwq[1][r[i]];
			if(r[i-1]==r[i]) qwq[1][i] = 1;
			else qwq[1][i] = qwq[0][i]-max(0,r[i-1]-i);
		}
		for(int i=1;i<=n;i++) idx[r[i]] = i;
		long long ans = 0,preans = 0;
		for(int i=1;i<=n;i++){
			if(l[i]+1==i||l[i]==i) continue;
			long long nowans = 0;
			if(l[i]==l[i-1]&&l[i]<i-2) nowans = preans;
			else if(!mn[l[i]+1]||mn[l[i]+1]==l[i]) nowans = 0;
			else{
				for(int j=mn[l[i]+1];j<=idx[l[i]+1];j++){
					if(r[j-1]<l[i]) nowans+=cnt[1][j];
					else nowans++;
				}
			}
			preans = nowans;
			if(l[i+1]>l[i]+1) nowans*=qwq[1][i];
			ans+=nowans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
