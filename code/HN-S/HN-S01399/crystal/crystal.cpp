#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[110],z,k=0,p=0,o;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z+=a[i];
	}
	z%=n;
	o=m;
	for(int i=1;i<=n;i++){  
	for(int j=1;j<=m;j++){
		if(a[i]!=z&&a[i]<=z){
			a[i]++;
			k++;
			if(k==o){
				break;
			} 
		}
	}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==z){
			p++;
		}
	}
	cout<<p;
	return 0;
}
