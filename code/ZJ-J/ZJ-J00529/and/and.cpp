#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=INT_MIN;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			x=max(x,a[i]);
		}
	}else if(m==n){
		x=a[0];
		for(int i=1;i<n;i++){
			x&=a[i];
		}
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					x=max(x,a[i]&a[j]);
				}
			}
		}
	}else if(m==n-1){
		for(int i=0;i<n;i++){
			int t=a[0];
			for(int j=1;j<n;j++){
				if(i!=j){
					t&=a[j];
				}
			}
			x=max(x,t);
		}
	}else{
		x=a[n-1];
	}
	cout<<x<<"\n";
	return 0;
}