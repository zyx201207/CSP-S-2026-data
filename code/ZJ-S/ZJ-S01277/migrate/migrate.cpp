#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int C,T,n,m,c[1014514<<1];
int dis[314][314],cnt[314][314];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
//		if(C<=6)
		int ans=0;
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		for(int i=1,tag=1;i<=n;i++){
			dis[i][i]=0;
			while(c[i]-c[tag]>m) tag++;
//			cout<<tag<<" "; 
			for(int k=1;k<tag;k++) dis[i][k]=1e11;
			for(int j=tag;j<i;j++){
				dis[i][j]=1;
				cnt[i][j]=1;
				for(int k=tag-1;k>=1;k--){
					if(dis[j][k]+1<dis[i][k]){
						dis[i][k]=dis[j][k]+1;
						cnt[i][k]=cnt[j][k];
					}
					else if(dis[j][k]+1==dis[i][k]) cnt[i][k]++;
					else break;
				} 
			}
			int t=0;
			for(int k=1;k<tag;k++){
				if(cnt[i][k]==2) t++;
			}
//			cout<<t<<" ";
			ans+=t;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1h36min
//24pts,n^3
//1h57min
//no inprovement
//I may need 1h to code T4 baoli;
//2h16min
//It looks like I'm getting the zhengjie
//2h25min
//I can't 

//1 1 2 3 4 4 5 7 8 9
//
//0 0 0 0 0 0 4 4 4 4


