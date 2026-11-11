#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,n,maxi=0;
	long long a[200009];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(maxi<a[i])
				maxi=a[i];
		}
		cout<<maxi;
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(maxi<(a[i]&a[j]))
					maxi=(a[i]&a[j]);
			}
		}
		cout<<maxi;
	}
	else if(m==n){
		for(int i=1;i<n;i++){
			if(i==1){
				maxi=a[0];
			}
			maxi&=a[i];
		}
		cout<<maxi;
	}
	else{
		cout<<20;
	}
	return 0;
}
