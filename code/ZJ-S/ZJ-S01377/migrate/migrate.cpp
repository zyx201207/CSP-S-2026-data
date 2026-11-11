#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum;
long long dis[2000005],num[2000005],a[2000005];
void dfs(long long x,long long step){
	if(x>n){
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			if(step+1==dis[i]){
				num[i]++;
			}
			dfs(i,step+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		cout<<"\n";
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			memset(num,0,sizeof(num));
			memset(dis,-1,sizeof(dis));
			long long x=1,w=a[i];
			for(int j=i+1;j<=n;j++){
				if(a[j]-w<=d){
					dis[j]=x;
				}
				else{
					if(a[j]-a[j-1]>d){
						break;
					}
					else{
						x++;
						w=a[j-1];
						dis[j]=x;
					}
				}
			}
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(num[j]==2){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return  0;
}
