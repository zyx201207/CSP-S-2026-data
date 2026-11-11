#include<bits/stdc++.h>
using namespace std;
int c,t,n,cnt_l[2000002],cnt_r[2000002];
long long d,x[2000002],ans;
queue<pair<int,int>>q; 
vector<int>to_l[5002],to_r[5002];
bool vis[2000002];
int dist[302],dif[302];
void solve(){
	
	for(int l=1;l<=n;l++){
		for(int r=l+3;r<=n;r++){
//			cout<<"!!!!!!!!!!!!!!!!!";
//			cout<<l<<" "<<r<<endl;
			for(int i=1;i<=n;i++){
				dist[i]=1e9;
				dif[i]=0;
			}
			dist[l]=0;
			dif[l]=1;
			for(int from=l;from<r;from++){
				for(int to=from+1;to<=n&&x[to]<=x[from]+d;to++){
//					cout<<from<<" "<<to<<endl;
					if(dist[to]>dist[from]+1){
						dist[to]=dist[from]+1;
						dif[to]=dif[from];
//						cout<<"down\n";
					}
					else if(dist[to]==dist[from]+1){
						dif[to]+=dif[from];
//						cout<<"add\n";
					}
				}
			}
//			cout<<"cishi:"<<dif[r]<<endl;
			if(dif[r]==2){
				ans++;
//				cout<<"could"<<endl;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;//岛屿数量 海鸟一次最多能飞行的距离
		for(int i=1;i<=n;i++){
			cin>>x[i]; 
			cnt_l[i]=cnt_r[i]=1;
			vis[i]=0;
		}
		if(n<=300){
			solve();
			continue;
		}
		for(int l=n,r=n,i=n-1;i>=2;i--){//当i=n时必不可扩展 
			while(l-1>i&&x[i-1]+d<x[l-1]&&x[i]+d>=x[l-1])l--;
			while(r>=l&&(x[i-1]+d>=x[r]||x[i]+d<x[r]))r--;
			for(int j=l;j<=r;j++)cnt_r[i]+=cnt_r[j];
		}
		for(int l=1,r=1,i=2;i<n;i++){
			while(r+1<i&&x[i]-d<=x[r+1]&&x[i+1]-d>x[r+1])r++;
			while(l<=r&&(x[i]-d>x[l]||x[i+1]-d<=x[l]))l++;
			for(int j=l;j<=r;j++)cnt_l[i]+=cnt_l[j];
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<cnt_l[i]<<" "<<cnt_r[i]<<endl;
//		}
		ans=0;
		for(int l=1,mx=1,r=1;l<n;l++){
			while(mx<n&&x[l]+d>=x[mx+1])mx++;//l最右可到mx
//			cout<<l<<" "<<mx;
			if(l+1<mx){
				while(r<n&&x[mx-1]+d>=x[r+1])r++;//mx-1最右可到r
//				cout<<"enter:"<<r; 
				for(int i=r;x[mx-2]+d<x[i];i--){
					ans+=1ll*cnt_l[l]*cnt_r[i];
//					cout<<endl<<"get_q:"<<l<<" "<<i<<endl;
//					cout<<"add:"<<1ll*cnt_l[l]*cnt_r[i];
				}
			} 
//			cout<<endl;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
