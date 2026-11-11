#include<bits/stdc++.h>
#define int long long
using namespace std;
int fy[500000];
int ls[500000];
int vis[500000];
int dis[6000][6000];
vector<int> mp[6000];
int cd,n,a,b,t;
long long fst;
int rd(){
	t=0;
	char c;
	while(1){
		c=getchar();
		if(c==' '||c=='\n'){
			return t;
		}
		t=t*10+c-'0';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cd>>n;
	while(n--){
		//cout<<n<<endl;
		cin>>a>>b;
		cin>>fst;
		int tk=1;
		ls[1]=0;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a;j++){
				dis[i][j]=-2;
			}
		}
		for(int i=2;i<=a;i++){
			cin>>ls[i];
			ls[i]-=fst;
		}
		for(int i=1;i<a;i++){
			for(int j=i+1;j<=a;j++){
				//cout<<ls[i]<<' '<<ls[j]<<endl;
				if(ls[j]-ls[i]<=b){
					//cout<<i<<' '<<j<<endl;
					mp[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		int now,cnt=0;
		queue<int> nt;
		for(int i=1;i<=a;i++){
			nt.push(i);
			while(!nt.empty()){
				int k=nt.front();
				nt.pop();
				for(int v:mp[k]){
					if(vis[v]){
						if(vis[v]==2&&dis[i][v]==dis[i][k]+1){
							cnt--;
							vis[v]=3;
						}
						if(dis[i][v]==dis[i][k]+1&&vis[v]==1){
							//cout<<i<<' '<<k<<' '<<v<<endl;
							vis[v]=2;
							cnt++;
						}
						continue;
					}
					if(vis[k]+vis[v]==2){
						vis[v]=2;
						cnt++;
					}
					else if(vis[k]+vis[v]>2&&vis[v]==2){
						vis[v]=3;
						cnt--;
					}
					else{
						vis[v]=1;
					}
					dis[i][v]=dis[i][k]+1;
					nt.push(v);
				}
			}
			for(int j=1;j<=a;j++){
				vis[j]=0;
			}
		}
		cout<<cnt<<endl;
		for(int i=1;i<=a;i++){
			mp[i].clear();
		}
	}
	return 0;
}
