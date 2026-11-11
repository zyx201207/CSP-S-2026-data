#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[10005];
long long k[10005];
long long a[55][55][55];
long long b[55][55];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j][1]>>a[i][j][2];
		}
	}
	for(long long i=1;i<=q;i++){
		long long kkk=1;
		cin>>b[i][1]>>b[i][2];
		long long sum=w[b[i][1]]+w[b[i][2]];
		for(long long j=1;j<=n;j++){
			for(long long v=1;v<=k[j];v++){
				if(a[j][v][1]==b[i][1]){
					for(long long f=1;f<=k[j];f++){
						if(a[j][f][1]==b[i][2]){
							sum=sum+a[j][v][2]+a[j][f][2];
							cout<<sum<<"\n";
							kkk=0;
							break;
						}
					}
					if(kkk==0){
						break;
					}
				}
			}
			if(kkk==0){
				break;
			}
		}
	}
	return 0;
}
