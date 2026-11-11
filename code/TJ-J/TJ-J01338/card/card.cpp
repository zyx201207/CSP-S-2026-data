#include<bits/stdc++.h>

using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum[m+10]={0};
	
	for(int p=1;p<=n;p++){//局数 
	    int y[n+10];
		int t=p-1; 
	    int o=p;
		for(int i=p;i<=n;i++){//每回合抽取的 
			y[i]=a[i];
			t++;
			for(int j=o;j<t;j++){
			 	if(a[i]==y[j]){
			 		//for(int k=o;k<i;k++){
			 		//	sum[y[i]]++;
					//}
			 		o=i;
				}
			}
		}
		for(int i=o;i<=t;i++){
			sum[y[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	 
	return 0;
}
