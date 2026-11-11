#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,c,a[2000010],dp[5555][5555],ct[5555][5555];
int mp[5555][5555];
void SLO(){
	cin>>n>>d;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	if (c<=10){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				mp[i][j]=0;
				ct[i][j]=0;
				dp[i][j]=0;
			}
		}
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (i==j) continue;
				if (abs(a[i]-a[j])<=d){
					mp[i][j]=mp[j][i]=1;
					ct[i][j]=ct[j][i]=1;
				}
			}
		}
//		for (int i=1;i<=n;++i){
//			for (int j=1;j<=n;++j){
//				if (mp[i][j]==0){
//					cout<<"0";
//				}else{
//					cout<<"1";
//				}
//			}
//			cout<<endl;
//		}
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (mp[i][j]==1){
					dp[i][j]=1;
				}else{
					dp[i][j]=1000000000;
				}
			}
			dp[i][i]=0;
		}
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				for (int k=1;k<=n;++k){
					if (j==k || i==j || i==k) continue;
					//cout<<j<<" "<<k<<" "<<i<<" "<<dp[j][k]<<" "<<dp[j][i]<<" "<<dp[i][k]<<endl;
					//if (mp[j][i]==1 && mp[i][k]==1)
						dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
				}
			}
		}
//		for (int i=1;i<=n;++i){
//			for (int j=1;j<=n;++j){
//				if (dp[i][j]==1000000000){
//					cout<<"- ";
//				}else{
//					cout<<dp[i][j]<<" ";
//				}
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				for (int k=1;k<=n;++k){
					if (j==k || i==j || i==k) continue;
					if (
					dp[i][k]+dp[k][j]==dp[i][j]){
						ct[i][j]+=1;
					}
				}
			}
		}
//		for (int i=1;i<=n;++i){
//			for (int j=1;j<=n;++j){
//				cout<<ct[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		int ans=0;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (ct[i][j]==2){
					++ans;
					//cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans/2<<endl;
	}else if (c==11 || c==12){
		
	}else if (c==13 || c==14){
		
	}else{
		cout<<"bu ke yi zong si ling"<<endl;
	}
}
/*
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
79 99 79 99 79 99 79 99 79 99 79 99 79 99 79 99
*/
signed main(){
	//freopen(".in","r",stdin)
	//freopen(".out","w",stdout)
	//wo zhi dao ni xiang kan shen me
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	int _;
	cin>>c>>_;
	while (_--){
		SLO();
	}
	return 0;
}
