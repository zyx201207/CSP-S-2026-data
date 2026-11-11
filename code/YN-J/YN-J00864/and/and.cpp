#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],vis[N],n,m,ans;
bool is2X(int item){
	if(item%2==0) return is2X(item/2);
	else if(item%2==1&&item!=1) return false;
	else return true;
}
bool checkA(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(is2X(a[i]+1)){
			cnt++;
		}
	}
	return cnt==n;
}
bool checkB(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i-1){
			cnt++;
		}
	}
	return cnt==n;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		pair<int,pair<int,int>>maxx={0,{0,0}};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int ind;
				if(i!=j){
					ind=(a[i]&a[j]);
					if(ind>maxx.first){
						maxx={ind,{i,j}};
					}
				} 
			}
		}
		ans=maxx.first;
		vis[maxx.second.first]=1;
		vis[maxx.second.second]=1;
		for(int k=3;k<=m;k++){
			maxx={0,{0,0}};
			for(int i=1;i<=n;i++){
				int ind;
				if(vis[i]==0){
					ind=(ans&a[i]);
					if(ind>maxx.first){
						maxx={ind,{0,i}};
					}
				}
			}
			ans=maxx.first;
			vis[maxx.second.second]=1;
		}
	}else if(n<=2000&&m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		ans=maxx;
	}else if(n<=2000&&m==n){
		int ind;
		for(int i=1;i<=n;i++){
			ind&=a[i];
		}
		ans=ind;
	}else if(m==2){
		pair<int,pair<int,int>>maxx={0,{0,0}};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int ind;
				if(i!=j){
					ind=(a[i]&a[j]);
					if(ind>maxx.first){
						maxx={ind,{i,j}};
					}
				} 
			}
		}
		ans=maxx.first;
	}else if(checkA()){
		int minn=INT_MAX;
		for(int i=1;i<=n;i++){
			minn=min(minn,a[i]);
		}
		ans=minn;
	}else if(/*true*/checkB()&&is2X(n)/**/){
		pair<int,int>sum={0,0};
		sum.first=(a[n-1]&a[n]);
		sum.second+=2;
		for(int i=n-1;i>=1;i--){
			if(sum.second==m) break;
			sum.first&=a[i];
			sum.second++;
		}
		ans=sum.first;
	}
	cout<<ans;
	return 0;
}
