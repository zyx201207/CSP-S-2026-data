#include<bits/stdc++.h>
using namespace std;
int a[200005],mx,mxx,nn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]){
			mx=a[i];
		}
	}
	nn=a[1];
	for(int i=1;i<n;i++){
		nn=nn&a[i+1];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	else if(m==n){
		cout<<nn;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>mxx){
					mxx=a[i]&a[j];
				}
			}
		}
		cout<<mxx;
		return 0;
	}
	else{
		cout<<a[n];
	}
	return 0;
}
