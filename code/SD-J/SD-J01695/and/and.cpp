#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=0,maxx2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxx){
			maxx=a[i];
		}
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				if(a[i]&a[j]>=maxx2){
					maxx2=a[i]&a[j];
				}
			}
		}
		cout<<maxx2;
		return 0;
	}if(m==4){
		for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				for(int k=1+j;k<=n;k++){
				if(maxx2<=a[i]&a[j]&a[k]&a[l]){
					maxx2=a[i]&a[j]&a[k]&a[l];
				}
			}
			}
		}}
		cout<<maxx2;
		return 0;
	}else if(m==n){
		maxx2=a[1];
		for(int i=2;i<=n;i++){
			maxx2=maxx2&=a[i];
		}
		cout<<maxx2;
	}
	return 0;
} 
