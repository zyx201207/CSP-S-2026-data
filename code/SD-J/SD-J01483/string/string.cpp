#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
vector<pair<int,char> >G;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,res=0;
	cin>>n;
	G.push_back({0,'0'});
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		res+=x;
		G.push_back({x,c});
	}
	int sum=0,xb=0;
	for(int i=1;i<=n;i++){
		sum+=G[i].first;
		if(sum>res/2){
			xb=i-1;
			sum-=G[i].first;
			break;
		}
	}
	//cout<<res<<" "<<sum<<"\n";
	int pos=0,lst=n,cost=0,ts=0;
	for(int i=1;i<=xb;i++){
		pos=G[i].first;
		int cnt=0,gs=0;
		
		for(int j=lst;j>xb;j--){
			cnt+=G[j].first;
			if(cnt>=pos){
				gs=j+1;
				cnt-=G[j].first;
				break;
			}
		}
		//cout<<gs<<" ";
		for(int j=gs;j<=lst;j++){
			ts+=G[j].first;
			if(G[j].second!=G[i].second)cost+=G[j].first;
			G[j].first=0;
		}
		if(G[gs-1].second!=G[i].second){
			cost+=(pos-cnt);
		}
		ts+=(pos-cnt);
		G[gs-1].first-=(pos-cnt);
		lst=gs-1;
		G[i].first=0;
	}
	int ans=0,wz=0;
	for(int i=xb+1;i<=n;i++){
		ans+=G[i].first;
		if(!G[i].first){
			wz=i-1;
			break;
		}
	}
	for(int i=xb+2;i<=wz;i++){
		if(G[i].second!=G[xb+1].second){
			cost+=G[i].first;
		}
	}
	//cout<<wz-xb+1<<" "<<sum<<"\n";
	cout<<cost;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
