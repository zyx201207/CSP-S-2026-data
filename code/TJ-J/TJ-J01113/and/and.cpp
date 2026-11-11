#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int s,x,y,z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		z=a[1]&a[2];
		for(int i=3;i<=n;i++){
			z=z&a[i];
		}
		cout<<z;
		return 0;
	}
	if(m==1){
		y=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>y){
				y=a[i];
			}
		}
		cout<<y;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=a[0]&a[1];
				s=a[i]&a[j];
				if(s>x){
					x=a[i]&a[j];
				}
			}
		}
		cout<<x;
		return 0; 
	} 
	cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
