#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=0;i<n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(m==n){
		int mx=a[0];
		for(int i=1;i<n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
	}
	else if(m==2){
		int mx=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	return 0;
}
