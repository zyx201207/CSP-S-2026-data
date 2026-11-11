#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			mx=max(mx,a);
		}
		cout<<mx; 
	}
	if(m==n){
		int mx;
		cin>>mx;
		for(int i=2;i<=n;i++){
			int a;
			cin>>a;
			mx=mx&a;
		}
		cout<<mx; 
	}
	if(m==2){
		int mx=0;
		int a[n+10];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	return 0;
} 
