#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,max=-1,a[500005];
	int num;
	long long m; 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool q=0;
	for(int i=0;i<n;i++){
		if(a[i]!=a[i-1]){
			q=1;
		}
	}	
	if(q==0){
		cout<<n;
		return 0;
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		int x=i;
		while(x--){
			bool c=0;
			int t=m;
			
			for(int j=i+1;j<x;j++){
				
				if(t>a[j]){
					t-=a[i]-a[j];
					
				}else{
					num=j;
					c=1;
					break;
				}
			}
		}	
		if(max<num){
			max=num;
		}
	}
	cout<<num;
	return 0;
} 
