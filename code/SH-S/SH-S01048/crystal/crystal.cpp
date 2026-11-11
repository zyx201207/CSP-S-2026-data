#include <iostream>
using namespace std;
int n;
int m;
int max1=0;
int max2=0;
int main(){
	cin>>n;
	cin>>m;
	int all[n];
	
	int pan[n];
	for (int i=0;i<n;i++){
		cin>>all[i];
		if (all[i]>max1){
			max1=all[i];
		}
	}
	for (int i=0;i<max1;i++){
		for (int j=0;j<n;j++){
			if (all[j]<=i){
				pan[j]=i-all[j];
			}
			else{
				pan[j]=1000;
			}
			
		}//到此统计完差值 
		
		
		int a=0;
		for (int j=0;j<n;j++){
			for (int k=0;k<n-j;k++){
				if (pan[k]>pan[k+1]){
					a=pan[k];
					pan[k]=pan[k+1];
					pan[k+1]=a;
				}
			}
		
		}//到此已排序 
		int count=0;
		int h=m;
		for (int j=0;j<n;j++){
			if (h>=pan[j]){
				count++;
				h-=pan[j];
			}
		}
		if (count>max2){
			max2=count;
		}
	
	
	
	}
	cout<<max2;
	return 0; 
}
