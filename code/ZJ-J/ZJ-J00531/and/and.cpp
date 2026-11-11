#include<bits/stdc++.h>
using namespace std;
int a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}	
	}
	if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx=(mx&a[i]);
		}
	}
	cout<<mx;
	return 0;
}