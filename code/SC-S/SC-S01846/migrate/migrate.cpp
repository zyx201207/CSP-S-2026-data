#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[5000005],mn[505][505];
int ans,cnt;
void dfs(int X,int k,int zmx,int en){
	//cout<<"oop1"<<X<<" "<<k<<" "<<zmx<<" "<<en<<endl;
	if(k>zmx) return;
	if(X>en) return;
	if(X==en){
		if(k==zmx) cnt++;
		return;
	}
	for(int i=X+1;i<=en;i++){
		if(x[i]-x[X]>d) break;
		//cout<<"oop2"<<X<<' '<<i+1<<" "<<k+1<<endl;
		dfs(i,k+1,zmx,en);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<"OK";
	cin>>c>>T;
	while(T--){
		bool fa=1;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) {cin>>x[i];if(i>=3 && x[i]-x[i-1]!=x[2]-x[1]) fa=0;}
		if(fa){
			if(d<=x[2]-x[1]){
				cout<<"0\n";
				continue;
			}
			int p=2*(d/(x[2]-x[1]));
			cout<<max((int)0,n-p+1)<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int j=i+1,k=x[i],p=0;
			while(j<=n){
				k+=d;
				p++;
				while(j<=n && x[j]<=k) {mn[i][j]=p;j++;}
			}
		}
		//dfs(1,0,mn[1][n],n);		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				dfs(i,0,mn[i][j],j);
				
				if(cnt==2) {ans++;}
			}
		}
		cout<<ans<<"\n";	
	}
	return 0;
}//90+4*4=106