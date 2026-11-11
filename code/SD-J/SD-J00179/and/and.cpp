#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+300;
int a[N],n,m,hav[51];
int fid[51][N];
vector<int>vis[51],vis2[51];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],cnt=0;
		while(x!=0){
			cnt++;
			if(x%2==1){
				hav[cnt]+=1;
				fid[cnt][i]=1;
				vis[cnt].push_back(i);
			}
			x/=2;
		}
	}
	int cnt=0;
	for(int i=51;i>=1;i--){
		if(hav[i]>=m){
			cnt=i;
			for(int j=0;j<vis[i].size();j++){
				vis2[i].push_back(vis[i][j]);
			}
			break;
		}
	}
	for(int i=cnt-1;i>=1;i--){
		if(hav[i]>=m){
			int count=0;
			for(int j=0;j<vis2[i+1].size();j++){
				if(fid[i][vis2[i+1][j]]==1){
					count+=1;
					vis2[i].push_back(vis2[i+1][j]);
				}
			}
			if(count<m){
				swap(vis2[i+1],vis2[i]);
			}
		}
		else{
			swap(vis2[i+1],vis2[i]);
		}
	}
	if(vis2[1].size()==0){
		cout<<0;
		return 0;
	} 
	int ans=a[vis2[1][0]];
	for(int i=1;i<vis2[1].size();i++){
		ans=ans&a[vis2[1][i]];
	}
	cout<<ans;
	return 0;
} 
