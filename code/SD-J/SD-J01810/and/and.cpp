#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		int c,a;
		cin>>a;
		for(int i=0;i<n;i++){
			cin>>c;
			a=c&a;
		}
		cout<<a<<endl;
		return 0;
	}
	int arr[200003]={0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	int max1=-1;
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				max1=max(max1,arr[i]&arr[j]);
			}
		}
		cout<<max1<<endl;
		return 0;
	}
	
/*	if(m==1&&m==n-1){
		for(int i=0;i<n;i++){
			int num=arr[i];
			while(num){
				
			}
		}
		
		
		
	}
	
	
	
	*/
	return 0;
}
