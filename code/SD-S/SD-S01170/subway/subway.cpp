#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1050;
const int M=5e5+10;
int w[N],a[M],t[M],huan[M],k[N];
//一绿三黑 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<int,int>mp[M];//mp<地铁站名,站厅到站台的时间> 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		
		cin>>k[i];
		for(int j=1;j<=k[i]/2;j++){
			cin>>a[i]>>t[i];
			mp[a[i]][i]=t[i];
		}
	}//思路：尽量不要换乘 
	int ans=0;
	while(q--){
		ans=0;
		int x,y,minn=-1e9;
		cin>>x>>y;
		int sub=0;
		for(int i=1;i<=n;i++){//寻找当前地铁站的线路；
			for(int j=2;j<=k[i]/2;j++){
				if(mp[j][i]==x){
					sub=mp[j][i];
				}
			}	
		}
		ans+=(w[x]+mp[sub][x]);
		if(mp[sub].find(y)!=mp[sub].end()){//在同一个线路上 
			ans+=(w[y]+t[y]);
		}else{//需要换乘
			for(int i=1;i<=n;i++){//找换乘点 
				for(int j=2;j<=k[i]/2;j++){
					if(mp[i].find(j)!=mp[i].end()&&mp[sub].find(j)!=mp[sub].end()){//awa终于找到了
						ans+=(mp[y][i]+mp[j][i]);//到站厅+到站台 
						if(mp[j].find(y)!=mp[j].end()){//别换乘了！orz 
							//hmm这里是不是还要判断这货换乘花费时间最小
							 minn=min(w[y]+t[y],minn);
						}
					}
				}
			}
			//找完了给minn加上
			ans+=minn; 
		}
		cout<<ans;
	} 
	return 0;
}
