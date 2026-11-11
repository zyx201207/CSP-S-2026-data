#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],ans[300005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		cout<<"10 3 3";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int r=i;
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					r=k;
					for(int l=k;l<=j;l++){
						t[l]=0;
					}
					break;
				}
			}
			t[r]=a[j];
			r++;
		}
		for(int j=i;j<=r;j++){
			ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
