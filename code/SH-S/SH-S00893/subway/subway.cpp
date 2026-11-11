#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
int c,n,m,d,q;
int ta[505][20005];//站台，地铁 
int vis[505];

int dfs(int pos,int zhong,int tim,int di){
//	vis[pos]=1;
	if(pos==zhong){
		return tim;
	}
	int minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(ta[pos][i]!=0&&ta[zhong][i]!=0){
			if(di==i){
				return tim;
			}
			else{
				return tim+ta[pos][di]+ta[pos][i]+ta[zhong][i];
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		
		if(ta[pos][i]!=0&&i!=di){
			int timm=tim+ta[pos][di]+ta[pos][i];
//			cout<<pos<<" "<<i<<" "<<di<<endl;
//			cout<<tim<<" "<<ta[pos][di]<<" "<<ta[pos][i]<<endl;
			if(ta[zhong][i]!=0){
				return timm+ta[zhong][i];
			}
			for(int j=pos+1;j<=zhong;j++){
				if(ta[j][i]!=0&&vis[j]==0){
					vis[j]=1;
					minn=min(minn,dfs(j,zhong,timm,i));
					vis[j]=0;
				}
			}
			for(int j=pos-1;j>=1;j--){
				if(ta[j][i]!=0&&vis[j]==0){
					vis[j]=1;
					minn=min(minn,dfs(j,zhong,timm,i));
					vis[j]=0;
				}
			}
//			ta[pos][i]
//pos站台，第i地铁	
		}
		else if(i==di){
//			cout<<1<<endl;
			for(int j=pos+1;j<=zhong;j++){
				if(ta[j][i]!=0&&vis[j]==0){
//					cout<<j<<endl;
					vis[j]=1;
					minn=min(minn,dfs(j,zhong,tim,i));
					vis[j]=0;
//					cout<<dfs(j,zhong,tim,j)<<endl;
//					cout<<minn<<endl;
				}
			}
			for(int j=pos-1;j>=1;j--){
				if(ta[j][i]!=0&&vis[j]==0){
//					cout<<j<<endl;
					vis[j]=1;
					minn=min(minn,dfs(j,zhong,tim,i));
					vis[j]=0;
//					cout<<dfs(j,zhong,tim,j)<<endl;
//					cout<<minn<<endl;
				}
			}
		}
	}
	return minn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int qw,er;
			cin>>qw>>er;
			ta[qw][i]=er;
		}
	}
	for(int kkk=1;kkk<=q;kkk++){
		int x,y;
		cin>>x>>y;
		int f=0;
		for(int ii=1;ii<=n;ii++){
			if(ta[x][ii]!=0&&ta[y][ii]!=0){
				cout<<w[x]+ta[x][ii]+ta[y][ii]+w[y]<<endl;
				f=1;
				break;
			}
		}
		if(f==1){
//			cout<<"efj"<<endl;
			continue;
		}
//		cout<<"fjh"<<endl;
		int minnn=0x3f3f3f3f;
		for(int iii=1;iii<=n;iii++){
			if(ta[x][iii]!=0){
//				cout<<i<<" "<<dfs(x,y,0,i)<<endl;
				minnn=min(minnn,w[x]+ta[x][iii]+dfs(x,y,0,iii)+w[y]);
//				cout<<minnn<<endl;
			}
		}
		cout<<minnn<<endl;
	}
	return 0;
}
