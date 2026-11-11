#include<bits/stdc++.h>
using namespace std;

#define int long long
long long n,m,ans;
int a[200010],can[200010],can2[200010];
bool dis(int num,int much){
	return num&(1<<(much-1));
}
signed main(){
	freopen("and.in" ,"r",stdin );
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		can[i]=1;
	}
	ans= (1ll<<33) -1ll;
	for(int i=31;i>=1;i--){
		
		int numOfYes=0;
		for(int j=1;j<=n;j++){
			if(dis(a[j],i)==1&&can[j]==1){
				can2[j]=1;
				numOfYes++;
			}else{
				can2[j]=0;
			}
		}
		if(numOfYes>=m){
			for(int j=1;j<=n;j++){
				if(can2[j]==0){
					can[j]=0;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(can[i]){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
/*salt*/
