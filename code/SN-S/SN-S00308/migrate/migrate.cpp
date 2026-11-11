#include<bits/stdc++.h>
using namespace std;
const int N=2000010;

long long ans;
int c,t,n,d,a[N];
vector<int> s[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)
			s[i].clear();
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c<=10){
			int f[5010],dis[5010];
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(a[j]-a[i]<=d)
						s[i].push_back(j);
			for(int i=1;i<=n;i++){
				memset(dis,0x3f,sizeof(dis));
				memset(f,0,sizeof(f));
				dis[i]=0;f[i]=1;
				for(int k=i;k<=n;k++){
					if(f[k]==2)
						ans++;
					for(int v:s[k]){
						if(dis[v]==dis[k]+1)
							f[v]+=f[k];
						if(dis[v]>dis[k]+1){
							dis[v]=dis[k]+1;
							f[v]=f[k];
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
