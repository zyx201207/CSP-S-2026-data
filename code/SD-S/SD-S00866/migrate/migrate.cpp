#include <bits/stdc++.h>
using namespace std;
const int M=5000;
long long c,t,n,d,a[M+5],dis[M+5],fan[M+5],q[2*M+5];
vector<long long>g[M+5];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			int l=i;
			while (l<n&&llabs(a[l+1]-a[i])<=d){
				l++;
				g[i].push_back(l);//cout<<i<<" "<<l<<endl;
			}
		}
		long long ans=0;
		for (int cas=1;cas<=n;cas++){
			for (int i=1;i<=n;i++){
				dis[i]=(1LL<<60);
				fan[i]=0;
			}
			dis[cas]=0;
			fan[cas]=1;
			long long head=1,tail=0;
			q[++tail]=cas;
			while (head<=tail){
				long long x=q[head];
				head++;
				for (int i=0;i<g[x].size();i++){
					long long ch=g[x][i];
					if (dis[x]+1<dis[ch]){
						dis[ch]=dis[x]+1;
						fan[ch]=fan[x];
						q[++tail]=ch;
					}
					else if (dis[x]+1==dis[ch]){
						fan[ch]+=fan[x];
					}
				}
			}
			for (int i=cas+1;i<=n;i++){
				if (fan[i]==2)ans++;//cout<<dis[i]<<" "<<fan[i]<<"	";
			}//cout<<endl;
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}

