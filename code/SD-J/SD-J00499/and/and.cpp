#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	int ans=0;
	if(n<=20){
		for(int k=0;k<=(1<<n);k++){
		int sum=0,t=(1<<21)-1;
		for(int j=0;j<=20;j++){
			if(k&(1<<j)){
				t&=a[j];
				sum++;
			}
		}
		if(sum==m){
			ans=max(ans,t);
			}
		}
		cout<<ans;
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		} 
		cout<<ans;
	}else if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		int t=(1<<21)-1;
		for(int i=0;i<n;i++){
			t&=a[i];
		}
		cout<<t;
	}
	return 0;
} 
