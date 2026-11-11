#include<iostream>
using namespace std;
int n,m,a[500005],dp[500005],maxn[500005],step[500005],total =0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	} 
	for(int i =1;i <=n ;i ++){
		for(int j = i;j <= n; j++){
			if(a[i]>a[j]){
				swap(a[i] , a[j]);
			}			
		}
	}
	for(int i = 1;i <= n;i ++){
       	for(int j = 2;j <= n;j ++){
       	    	maxn[i] += a[i] - a[j]; 
       	    	dp[i] ++;
       	    	if(m - maxn[i] == a[j] - a[i]) break;
		}
	}	
	for(int i = 1;i <= n;i++){
		total = max(dp[i],dp[i+1]);
	}
	cout<<total; 
	return 0;
} 
