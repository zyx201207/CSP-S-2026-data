#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int max_=-1e9; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m=1){
		for(int i=0;i<n;i++){
			if(a[i]>max_){
				max_=a[i];
			}
		}
	}else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]&a[j]>max_){
					max_=a[i]&a[j];
				}
			}
		}
	}
	cout<<max_;	
	return 0; 
}
