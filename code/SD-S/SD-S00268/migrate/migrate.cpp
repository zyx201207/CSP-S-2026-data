#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int c,t,n,d,x[2000010];
int tstp[5010][5010];//两步能够到达的方案数量 
bool ostp[5010][5010];//一步可以到达 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(ostp,0,sizeof ostp);
		memset(tstp,0,sizeof tstp);
		cin>>n>>d;
		int last=n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1&&x[i]-x[i-1]>=d+1&&last==n){
				last=i;
			}
		}
		n=last;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i]+d>=x[j]){
					ostp[i][j]=true;
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				if(!ostp[i][j])
				    continue;
				for(int k=j+1;k<=n;k++){
					if(!ostp[j][k])
					    continue;
					tstp[i][k]++;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				if(tstp[i][j]==2&&ostp[i][j]==false){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
