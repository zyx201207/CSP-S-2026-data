#include<bits/stdc++.h>
using namespace std;
#define FILENAME "migrate"

long long c,t,n,d,x[5000001],cnt[5000001],ans,min_cnt;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);

	cin>>c>>t;
	cnt[1]=0;
	while(t--){
		cin>>n>>d;
		cin>>x[1];
		for(int i=2;i<=n;i++){
			min_cnt=0;
			cin>>x[i];
			cnt[i]=LLONG_MAX;
			for(int j=i-1;j && (x[i]-x[j]<=d);j--){
				cnt[i]=min(cnt[i],cnt[j]+1);
			}
			for(int j=i-1;j && (x[i]-x[j])<=d;j--){
				if(cnt[j]+1==cnt[i]) min_cnt++;
				if(min_cnt>2) break;
			}
			if(min_cnt==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}