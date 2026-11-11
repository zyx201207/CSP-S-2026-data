#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	} 
	mx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int b=a[i]&a[j];
			mx=max(mx,b);
		}
	}
	cout<<mx;
	return 0;
} 
