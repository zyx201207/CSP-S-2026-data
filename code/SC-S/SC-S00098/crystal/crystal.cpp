#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int c=0,max=0,d=m,e=m;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		c=1;
		m=e;
		for(int j=0;j<d;j++){
			if(a[j+1]-a[j]<=m){
				m-=a[j+1];
				m+=a[i];
				c++;
			}
			if(m<0){
				break;
			}
		}
		if(max<=c){
			max=c;
		}
		d--;
		
		
	}
	max--;
	cout<<max;
	
	return 0;
}