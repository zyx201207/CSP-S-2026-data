#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500050];
long long a[550][200050]{0};
long long end_;
long long minn=10e+5;
void xxx(long long begin,long long time){
	for(long long i=1;i<=m;i++){
		if(a[i][begin]&&a[i][end_]){
			minn=min(minn,time);
			return;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
//			cout<<a[i][j]<<" "<<a[i][begin]<<" "<<i<<" "<<j<<" "<<begin<<endl;
			if(a[i][j]&&a[i][begin]&&j!=begin){
				int teep=a[i][begin];
				a[i][begin]=0;
				xxx(j,time+a[i][j]+teep);
				a[i][begin]=teep;
			}
		}
	}
	for(long long i=1;i<m;i++){
		for(long long j=i+1;j<=m;j++){
			if(a[i][begin]&&a[j][begin]){
				xxx(i,time);
				xxx(j,time);
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long aa;
		cin>>aa;
		for(long long j=1,k;j<=aa;j++){
			cin>>k;
			cin>>a[i][k];
		}
	}

	for(long long i=1;i<=q;i++){
		long long begin;
		cin>>begin>>end_;

		long long sum=0;
		sum+=w[begin]+w[end_];
		xxx(begin,0);
		sum+=minn;
		cout<<sum<<endl;
	}
	return 0;
}