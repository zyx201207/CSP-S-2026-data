#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ans; 
ll cost[N],sum[N];
int X=1,cha;
//²Ù×÷ +1 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	for(int i=1;i<=n;i++){
		if(i==1){
			cha==a[i];
		}
		else{
			if(a[i]-a[i-1]!=cha) X=0;
		}
		//cost[i]=a[i+1]-a[i];
		//cost[i]=cost[i-1]+a[i];
		if(i==n) continue;
		sum[i]=a[i]+sum[i-1];
		cost[i+1]=a[i+1]*i-sum[i];		
	}
	if(X){
		for(int i=1;i<=n;i++){
			if(cost[i]<=m)
				ans++;
		}
		if(ans==1) cout<<0;
		else cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++){
				if(cost[i]-cost[j]-(a[i]-a[j])*(j-1)<=m){
					//cout<<j<<" "<<i<<" "<<i-j+1<<"\n";
					ans=max(ans,ll(i-j+1));
				}
			}
		if(ans==1) cout<<0;	
		else cout<<ans;			
	}

//	for(int i=1;i<=n;i++){
//		cout<<cost[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	cout<<"\n";

	return 0;
} 
/*
5 5 
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4
*/
/*
 -WI -stack -536870912
*/
