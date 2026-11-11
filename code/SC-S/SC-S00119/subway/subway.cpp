#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50008],t,s,q,z,x,dp[1005][1005];//两点之间的最短距离 
vector<int> mp[50008]; 
struct nn{
	long long s,z;
};
vector<nn> sl; 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			dp[i][j]=1e9;//神圣的弗雷德 
		}
	} 
	cin>>t>>n>>m>>s>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//n个地铁 
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>z>>x;
			sl.push_back({z,x});//这趟车到点z,点权为x 
		}
		for(int j=0;j<t;j++){
			for(int k=0;k<t;k++){
				if(j==k)dp[sl[j].s][sl[j].s]=min(sl[j].z,dp[sl[j].s][sl[j].s]);
				else dp[sl[j].s][sl[k].s]=dp[sl[k].s][sl[j].s]=min(sl[j].z+sl[k].z,dp[sl[j].s][sl[k].s]);
//				cout<<"	"<<sl[j].s<<" "<<sl[k].s<<"\n";
			}
		}
		sl.clear();
	}
	/////////////神圣的建图结束了(就是不知道会不会~~TLE~~)
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
////			if(i==j)continue;
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
//			
//		}
//	}	
//	return 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			for(int k=1;k<=m;k++){
				if(k==j)continue;
				if(k==i)continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<k<<"\n";
			}
		}
	}
//	cout<<q<<"!!!!!!!!";
	for(int i=1;i<=q;i++){
		cin>>z>>x;
		
		cout<<dp[z][x]+a[z]+a[x]<<"\n";
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}//给点分吧,QwQ求求你了QwQ