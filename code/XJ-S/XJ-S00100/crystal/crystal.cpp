#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	//freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum[n];
	for (int i=0;i<n;i++){
		sum[i]=1;
	}
	int sb=0;//中间量 
	for (int i=0;i<n;i++){//考虑a[i]对于每个变量 
		for (int k=i+1;k<n;k++){
			if (a[k]<a[i]){
				sb=a[i];
				a[i]=a[k];
				a[k]=sb;
			}
		}//排序（大小） 
	}
	int all=0;//表示总和，不能超过m 
	for (int i=1;i<n;i++){
	    for (int j=i-1;j>=0;j--){
	    	all+=(a[i]-a[j]);
	    	if (all>m){
	    		break;
			}
			sum[i]+=1;
		}
		all=0;
	}//算每个 
	int max=sum[0];
	for (int i=1;i<n;i++){
		if(sum[i]>=max){
			max=sum[i];
		}
	}
	cout << max;
	return 0;
}
