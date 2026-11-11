#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_back
#define pof pop_back
#define ft first
#define sd second
#define endl '\n'
using namespace std;
long long c,t,n,d;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		bool te1=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3&&x[i]-x[i-1]!=x[i-1]-x[i-2]){
				te1=0;
			}
		}
		if(te1){
			long long cha=x[2]-x[1];
			long long op=d/cha;
			cout<<0<<endl;
		}
		else if(n<=300){
			long long ans=0;
			vector<long long> edge[310];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if((x[j]-x[i])<=d){
						edge[i].pb(j);
						edge[j].pb(i);
					}
				}
			}
			/*for(int i=1;i<=n;i++){
				for(auto nex:edge[i]){
					cout<<nex<<' ';
				}
				cout<<endl;
			}*/
			long long dis[310][310];
			unsigned long long lu[310][310];
			memset(dis,0x3f,sizeof(dis));
			for(int i=1;i<=n;i++){
				queue<long long> q;
				bool inq[310];
				memset(inq,0,sizeof(inq));
				dis[i][i]=0;
				lu[i][i]=1;
				q.push(i);
				while(!q.empty()){
					long long noww=q.front();
					q.pop();
					inq[noww]=0;
					for(auto nex:edge[noww]){
						if(dis[i][nex]>dis[i][noww]+1){
							dis[i][nex]=dis[i][noww]+1;
							lu[i][nex]=lu[i][noww];
							q.push(nex);
							inq[nex]=1;
						}
						else if(dis[i][nex]==dis[i][noww]+1){
							lu[i][nex]+=lu[i][noww];
							/*q.push(nex);
							inq[nex]=1;*/
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<dis[i][j]<<' ';
					ans+=(lu[i][j]==2);
				}
				//cout<<endl;
			}
			cout<<ans<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
