#include<bits/stdc++.h>
using namespace std;
long long d,a[500],step=0,mmin=1e9+10;
int t,n,sum=0,num=0;
bool vis[5005]={1},ddd=0;
void dfs(int n1,int n2){
	if(n1==n2&&step<=mmin){
		sum++;
		if(step<mmin){
			ddd++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==n1){
			continue;
		}
		if(a[n1]-a[i]<=d||a[i]-a[n1]<=d&&vis[i]){
			step+=max(a[n1]-a[n2],a[n2]-a[n1]);
			vis[i]=0;
			dfs(i,n2);
			vis[i]=1;
			step-=max(a[n1]-a[n2],a[n2]-a[n1]);
		}
	}
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c;
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		cin>>n>>d;
		num=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ddd=0;
				step=0;
				mmin=1e9+10;
				dfs(i,j);
				sum-=ddd;
				if(sum==2){
					num++;
				}
			}
		}
		cout<<num;
	}
	return 0;
}
