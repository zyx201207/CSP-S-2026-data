#include<bits/stdc++.h>
using namespace std;
struct node{
	long long dis,cnt;
};
node f[500+10][500+10];
long long p[2000000+10];
vector<long long>q[2000000+10];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,T;
	cin>>c>>T;
	while(T--){
		long long n,d,ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				f[i][j]={1e18,0};
			}
			q[i].clear();
		}
		for(long long i=1;i<=n;i++){
			cin>>p[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n && p[j]-p[i]<=d;j++){
				q[j].push_back(i);
				f[i][j]={1,1};
			}
		}
		for(long long k=2;k<n;k++){
			for(long long i=1;i+k<=n;i++){
				long long j=i+k;
				for(long long asd=0;asd<q[j].size();asd++){
					long long v=q[j][asd];
					if(i<v){
						if(f[i][j].dis>f[i][v].dis+1){
							f[i][j]=f[i][v];
							f[i][j].dis++;
//							cout<<1<<" "<<i<<"|"<<j<<"|"<<v<<" "<<f[i][j].cnt<<" "<<f[i][j].dis<<"\n";
						}else if(f[i][j].dis==f[i][v].dis+1){
							f[i][j].cnt+=f[i][v].cnt;
//							cout<<2<<" "<<i<<"|"<<j<<"|"<<v<<" "<<f[i][j].cnt<<" "<<f[i][j].dis<<"\n";
						}
					}
				}
//				cout<<i<<"|"<<j<<"|"<<f[i][j].dis<<"|"<<f[i][j].cnt<<"        ";
				if(f[i][j].cnt==2)ans++;
			}
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}