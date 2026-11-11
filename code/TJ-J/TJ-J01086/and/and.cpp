#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200010];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	unsigned long long mx=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
	}
	else if(m==2){
		unsigned long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==3){
		unsigned long long ansss=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					if(i==j||j==l||i==l){
						continue;
					}
					unsigned long long c=a[i]&a[j];
					ansss=max(ansss,c&a[l]);
				}
			}
		}
		cout<<ansss;
	}else{
		unsigned long long anss=a[1];
		for(int i=2;i<=n;i++){
			anss=anss&a[i];
		}
		cout<<anss;
	}
	return 0;
} 
