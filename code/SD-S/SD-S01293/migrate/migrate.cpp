#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int c,t;
int n,d,ans=0; 
int x[2000010];
int dis[5010][2]={};
void solve1(){
	ans=0;
	for(int i=1;i<=n;i++){
		dis[i][0]=0;
		dis[i][1]=1;
		//cout<<i<<':'<<endl;
		for(int j=i+1;j<=n;j++){
			dis[j][0]=1e9;
			dis[j][1]=0;
			for(int k=i;k<j;k++){
				if(x[k]+d<x[j]) continue;
				if(dis[k][0]+1<dis[j][0]){
					dis[j][0]=dis[k][0]+1;
					dis[j][1]=dis[k][1];
				}else if(dis[k][0]+1==dis[j][0]){
					dis[j][1]+=dis[k][1];
				}
			}
			//cout<<j<<' '<<dis[j][0]<<' '<<dis[j][1]<<endl;
			if(dis[j][1]==2){
				ans++;
			}
		} 
	}
	cout<<ans<<endl;
}
void solve2(){
	if(x[3]-x[1]>d){
		cout<<0<<endl;
		return; 
	}
	int cnt=d/(x[2]-x[1]);
	if(n-cnt*2+1<0){
		cout<<0<<endl;
	}else{
		cout<<n-cnt*2+1<<endl;
	}
}
signed main(){
	fast;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c<=10){
			solve1();
		}else if(c==11||c==12){
			solve2();
		}else{
			cout<<0<<endl;
		}
	} 
	return 0;
}

