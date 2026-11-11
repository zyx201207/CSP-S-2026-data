//SN-S00535 程谟然 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long w[500005]={};
long long a[500005]={};
long long t[810][810]={};
long long x[100005]={};
long long y[100005]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[j];
			cin>>t[a[j]][j];
		}
	}
	long long ans=0;
	for(long long i=1;i<=q;i++){
		ans=0;
		cin>>x[i]>>y[i];
		ans+=w[x[i]];
		for(long long j=1;j<y[i];j++){
			for(long long k=1;k<=j;k++){
				ans+=t[j][k];
			}
		}
		ans+=w[y[i]];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
