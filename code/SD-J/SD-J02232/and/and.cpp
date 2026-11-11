#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int n,m,ma=0,im=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(im<a[i]){
			im=a[i];
		}
	}
	if(m==1){
		cout<<im;
		return 0;
	}
	if(m==n){
		int z=a[0];
		for(int i=0;i<n;i++){
			z=(z&a[i]);
		}
		cout<<z;
		return 0;
	}
	for(int i=0;i<=n-m;i++){
		for(int j=i+1;j<n;j++){
			if(ma<(a[i]&a[j])){
				ma=(a[i]&a[j]);
			}
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
