#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	int n,m,a[100000],ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int u=a[i]&a[j];
				if(ans<u){
					ans=u;
				}
			}
		}cout<<ans;
	}if(m==n){
		int f=a[0]&a[1];
		for(int i=2;i<n;i++){
			ans=f&a[i];
		}cout<<ans;
	}if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>ans){
				ans=a[i];
			}
		}
		cout<<ans;
	}	
}
