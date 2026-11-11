#include<iostream>
using namespace std;
int n,m,a[1000000],maxn; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	maxn=-100000;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	maxn=a[1];
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			maxn=maxn&a[i];
		}
	}
	cout<<maxn;
	return 0;
}
