#include <bits/stdc++.h>
using namespace std;
int a[2000034];
int e1[200008],e2[200008];
int xiao[200008];
int h1,h2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,he,maxq=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(maxq<a[i]){
				maxq=a[i];
			}
		}
		cout<<maxq;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				int h1,h2;
				while(a[i]){
					if(a[i]%2){
						e1[i]=1;
					}else{
						e1[i]=0;
					}
					h1++;
					a[i]/=2;
				}
				while(a[j]){
					if(a[j]%2){
						e1[j]=1;
					}else{
						e1[j]=0;
					}
					h2++;
					a[j]/=2;
				}
				for(int l=0;l<max(h1,h2);i++){
					xiao[l]=e1[l] and e2[l];
				}
			}
		}
		int r=0,k;
		for(int i=0;i<max(h1,h2);i++){
			for(int j=0;j<r;j++){
				k*=2;
			}
			he+=xiao[i]*k;
		}
		cout<<he;
		return 0;
	}
	return 0;
}
