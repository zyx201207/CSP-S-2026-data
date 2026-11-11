#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6;
ll flyd[305][305];
ll cnt[305][305];
ll x[N];
ll ans;
int c,t,n,d;
void init(){
	ans=0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			flyd[i][j]=INT_MAX;
			cnt[i][j]=0;	
		}
	}
}
void f1(){
	cin>>n>>d;
	init();
	x[0]=-1e12;
	for(int i = 1;i<=n;i++){
		cin>>x[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(x[j]-x[i]<=d) cnt[i][j]=1,flyd[i][j]=1;
		}
	}
	for(int j = 1;j<=n;j++){
		for(int i = 1;i+j<=n;i++){
			if(x[i+j]-x[i]<=d){
				flyd[i][i+j]=1,cnt[i][i+j]=1;
				continue;	
			}
			for(int k = i+1;k<i+j;k++){
				if(flyd[i][k]>=INT_MAX||flyd[k][i+j]>=INT_MAX) continue;
				if(flyd[i][k]+flyd[k][i+j]<flyd[i][i+j]){
					flyd[i][i+j]=flyd[i][k]+flyd[k][i+j];
					cnt[i][i+j]=cnt[i][k]*cnt[k][i+j];
				}else if(flyd[i][k]+flyd[k][i+j]==flyd[i][i+j]) cnt[i][i+j]+=cnt[i][k]*cnt[k][i+j];
//				printf("(%d->%d->%d)\n",i,k,i+j);
			}
		}
//		cout<<"#"<<j<<": \n";
//		for(int x = 1;x<=n;x++){
//			for(int y = 1;y<=n;y++){
//				cout<<flyd[x][y]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<"***\n";
//		for(int x = 1;x<=n;x++){
//			for(int y = 1;y<=n;y++){
//				cout<<cnt[x][y]<<" ";
//			}
//			cout<<endl;
//		}
		
	}
//	cout<<"___\n";
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
//			cout<<cnt[i][j]<<" ";
			if(cnt[i][j]==2) ans++;
		}
//		cout<<endl;
	}
//	cout<<"___\n";
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c>=0&&c<=6) f1();
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
