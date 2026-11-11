#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int dp[n];
	/*
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}cout<<endl;
	*/
	for(int i=0;i<n;i++){
		int num = 0;
		int c = m;
		int s =0;
		for(int k =0;k<n;k++){
			if(a[k]<a[i]) s++;
		}
		while(c > 0 && num!=s+1){
			
			//memset(g,0,sizeof(g));
			int min = 9999999;
			int min_pos = i;
			int j = 0;
			for(;j<n;j++){
				
				if(a[i]-a[j]<=min && a[i] - a[j] > 0 ){
					min = a[i]-a[j];
					min_pos = j;
				}
			}
			
			if(a[i] - a[j]<=0){
				continue;
			}
			
			c -= min;
			num++;
			
			
			
			if(num == s+1){
				break;
			}
			
			

		}
		dp[i] = num;
	}
	int max = 0;
	for(int i=0;i<n;i++){
		
		if(max<dp[i]){
			max=dp[i];
		}
	}
	cout<<endl<<max;
	return 0;
} 