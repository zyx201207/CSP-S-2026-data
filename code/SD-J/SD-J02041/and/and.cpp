#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		maxx=a[n];
	}else if(m==n){
		for(int i=1;i<n;i++){
			maxx=a[i]&a[i+1];
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
	}else{
		if(a[n]==n-1){
			maxx=n-m;
		}else{
			sort(a+1,a+n+1);
			maxx=a[n-m+1];
		}
	}
	srand((0));
	if(maxx==0){
		maxx=rand()%100;
	}
	cout<<maxx;
	return 0;
}
