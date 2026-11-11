#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,f[1005][1005],chuqu[500005],lb[500005][25],vis[505][505],cnt[5000005],id[500005][55];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=501;i++)
	for(int j=1;j<=501;j++)
	vis[i][j]=f[i][j]=LONG_LONG_MAX/2;
	for(int i=1;i<=501;i++)
	vis[i][i]=f[i][i]=0;
	for(int i=1;i<=m;i++)
	cin>>chuqu[i];
	for(int i=1,N;i<=n;i++){
		cin>>N;
		for(int j=1,A,T;j<=N;j++){
			cin>>A>>T;
			cnt[A]+=1;
			lb[A][cnt[A]]=T,id[A][cnt[A]]=i;
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<cnt[i]<<"***\n";
//		for(int j=1;j<=cnt[i];j++){
//			cout<<lb[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++){//i:dian
		for(int j=1;j<=cnt[i];j++)//cong na lai
		for(int k=1;k<=cnt[i];k++){//dao na qu
			f[id[i][j]][id[i][k]]=vis[id[i][j]][id[i][k]]=min(vis[id[i][j]][id[i][k]],lb[i][j]+lb[i][k]);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//		if(f[i][j]==INT_MAX/2)cout<<"-1 ";
//		else cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--){
		int l,r;
		long long ans=LONG_LONG_MAX/2;
		cin>>l>>r;
		for(int i=1;i<=cnt[l];i++){
			for(int j=1;j<=cnt[r];j++){
//				cout<<id[l][i]<<" "<<id[r][j]<<" zhongjian "<<f[id[l][i]][id[r][j]]<<"????\n";
//				cout<<"\n\n\n";
//				cout<<l<<" "<<i<<"\n"<<lb[l][i]<<" "<<f[id[l][i]][id[r][j]]<<" "<<f[id[r][j]][id[l][i]]<<" "<<lb[r][j]<<" "<<r<<" "<<j<<"\n"<<"\n\n\n";
				ans=min((long long)(lb[l][i]+f[id[l][i]][id[r][j]]+lb[r][j]),ans);
			}
		}
		cout<<ans+chuqu[l]+chuqu[r]<<"\n";
	}
}//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3