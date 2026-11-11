#include<bits/stdc++.h>
using namespace std;
int sqrt2(int ca){
	int qwer=1;
	for(int i=1;i<=ca;i++)qwer*=2;
	return qwer;
}
int n,m;
bool b[500005][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=31;j++){
			if(a[i]==(a[i]|sqrt2(j)))b[i][j]=1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=31;j++){
//			cout<<b[i][j];
//		}
//		cout<<endl;
//	}
	bool wsx[n+1]={0};
	
	int maxx=32,ans12=0;int ans=0;
	while(maxx>0){
		for(int j=maxx-1;j>=0;j--){

			for(int i=1;i<=n;i++){

				if(wsx[i])continue;
				ans12+=b[i][j];
			}
			if(ans12>=m){maxx=j;break;}
			if(j==0)maxx=-1;
			ans12=0;
		}
		if(maxx!=-1){
			ans+=sqrt2(maxx);
			for(int i=1;i<=n;i++){
				if(a[i]!=(a[i]|sqrt2(maxx)))wsx[i]=1;
			}
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
