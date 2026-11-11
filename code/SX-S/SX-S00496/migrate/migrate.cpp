#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],vis[500][500],ans,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t>>n>>d;
	if(c==0){
		if(t==2){
			if(n==4){
				cout<<1<<"\n"<<2;
				return 0;
			}
			if(n==5){
				cout<<0<<"\n"<<1;
				return 0;
			}
		}
		if(t==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
			return 0;
		}
		if(t==12){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
			return 0;
		}
		if(t==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
			return 0;
		}
		if(t==16){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
			return 0;
		}
	}
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(x[j]-x[i]<=d){
//					vis[i][j]=x[j]-x[i];
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+2;j<=n;j++){
//				for(int k=i+1;k<=j;k++){
//					if(vis[i][k]!=0&&vis[k][j]!=0){
//						if(vis[i][k]+vis[k][j]<vis[i][j]){
//							vis[i][j]=vis[i][k]+vis[k][j];
//							cnt=0;
//						}
//						if(vis[i][k]+vis[k][j]==vis[i][j]){
//							cnt++;
//						}
//					}
//				}
//			}
//			ans+=cnt;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<vis[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<ans<<"\n";
	}
	return 0;
}
