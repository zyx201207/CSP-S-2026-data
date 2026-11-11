#include <bits/stdc++.h>
using namespace std;
int x[200010],start[200010],publ[200010],dp[200010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int l=1;
		for(int i=1;i<=n;i++){
			while(l<=i&&x[i]-x[l]>d){
				l++;
			}
			start[i]=l;
		}
		int finall=0;
		for(int l=1;l<=n;l++){
			publ[l]=0,dp[l]=1;
			int tre=l;
			for(int r=l+1;r<=n;r++){
				if(start[r]==r){
					break;
				}
				publ[r]=publ[max(l,start[r])];
				publ[r]+=1;
				tre=max(tre,max(start[r],l));
				while(tre<=r&&publ[tre]<=publ[r]-1){
					tre++;
				}
				dp[r]=dp[tre-1]-dp[max(start[r],l)-1];
				if(dp[r]==2){
					finall++;
				}
				dp[r]+=dp[r-1];
			}
			dp[l]=0;
		}
		if(t==0){
			cout<<finall;
		}
		else{
			cout<<finall<<endl;
		}
	} 
	return 0;
}

