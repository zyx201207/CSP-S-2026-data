#include <iostream>
#include <stdio.h>
using namespace std;

int x[1000005];
int zd;

int dp(int s,int e,int d0){
	if(x[e]-x[s]<=d0){
		return 1;
	}else{
		if(e<=s+1){
			return 0;
		}else{
			int mn=dp(s+1,e,d0);
			for(int i=0;i<e-s;i++){
				if(x[s+i]-x[s]<=d0){
					if(mn){
						mn=dp(s+i,e,d0)+1;
					}else if(dp(s+i,e,d0)){
						mn=min(mn,dp(s+i,e,d0)+1);
					}
				}else{
					break;
				}
			}
			return mn;
		}
	}
}

int dp2(int s,int e,int d0,int zdl,int ndl){
	if(x[e]-x[s]<=d0){
		if(zdl==ndl){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(e<=s+1){
			return 0;
		}else{
			int sum=0;
			for(int i=0;i<e-s;i++){
				if(x[s+i]-x[s]<=d0){
					sum+=dp2(s+i,e,d0,zdl,ndl+1);
				}else{
					break;
				}
			}
			return sum;
		}
	}
}

int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	int c,t;
	cin >> c >> t;
	for(int i=0;i<t;i++){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int dl=dp(i,j,d);
				
			}
		}
			
	}
	return 0;
}