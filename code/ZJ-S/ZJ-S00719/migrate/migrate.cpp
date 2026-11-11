#include<bits/stdc++.h>
using namespace std;
int c,t;
struct fn{
	long long s,c,l;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		long long a[20005];
		vector<fn>q[20005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		for(long long k=1;k<n;k++){
			for(long long i=1;i+k<=n;i++){
				if(a[i+k]-a[i]<=d){
					fn x;x.s=i+k;x.c=1;x.l=1;
					q[i].push_back(x);
					continue;
				}
				long long mi=10000000,dd;
				for(long long j=0;j<q[i].size();j++){
					for(long long l=0;l<q[q[i][j].s].size();l++){
						if(q[q[i][j].s][l].s==i+k){
							if(q[q[i][j].s][l].c+q[i][j].c<mi){
								mi=q[q[i][j].s][l].c+q[i][j].c;
								dd=q[q[i][j].s][l].l*q[i][j].l;
							}
							else if(q[q[i][j].s][l].c+q[i][j].c==mi){
								dd+=q[q[i][j].s][l].l*q[i][j].l;
							}
						}
					}
				}
				if(mi==10000000)continue;
				fn x;x.s=i+k;x.c=mi;x.l=dd;
				q[i].push_back(x);
				if(dd==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
