#include <bits/stdc++.h>
using namespace std;
int ans=0;
int minn=1000000000;
void mj(vector<int> vc,vector<int> dis,int p,int d){
		for(int i=1;i<p;i++){
			
			if(vc[i]+d>=vc[p]){
				
				minn=min(minn,dis[i]+1);
				dis[p]=minn;
			
				if(p==4){
			//	cout<<" p4>>"<<i<<" "<<dis[i]+1;	
				cout<<" "<<dis[i]+1<<" "<<minn<<" ";		
				}	
			}
		}
		int cnt=0;
		for(int i=1;i<p;i++){
			if(vc[i]+d>=vc[p]){
				if(dis[i]+1==minn) cnt++;
			}
		}
		dis[p]=minn;
		if(cnt==2) ans++;
	//	cout<<"\n"<<p<<"\n";
		for(int i=1;i<=p;i++){
	//			cout<<dis[i]<<" ";
		}
	//	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,d;
		cin>>n>>d;
		minn=100000000;
		vector<int> island(n+5);
		vector<int> dis(n+5);
		for(int i=1;i<=n;i++){
			dis[i]=20000000;
		}
		for(int i=1;i<=n;i++){
			cin>>island[i];
		}
		dis[0]=0;
		dis[1]=0;
		
		for(int i=2;i<=n;i++){
			minn=100000000;
			mj(island,dis,i,d);
			dis[i]=minn;
		//	for(int j=1;j<=n;j++){
		//		cout<<dis[j]<<" ";
		//	}
	 }
	//	for(int j=1;j<=n;j++){
	//			cout<<dis[j]<<" ";
	//	}
		cout<<ans<<'\n';
		//int c=island[2]-island[1];
		//bool dx=1;
		//for(int i=2;i<=n;i++){
		//	if(island[i]-island[i-1]!=c){
		//		dx=0;
		//		break;
		//	}
	//	}
		//if(dx==1){
	//		
		//}
	//	for(it i=n;i>=1;i--){
		//	island[i]
	//	}
	}
	return 0;
}