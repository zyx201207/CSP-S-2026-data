#include<bits/stdc++.h>
using namespace std;
int a[200005]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==m){
		h=a[1];
		for(int i=2;i<=n;i++){
			h=h&a[i];
		}	
		cout<<h;
		return 0;
	}
	else if(m==1)cout<<a[n];
	else if(m==n-1){
		h=a[2];
		for(int i=3;i<=n;i++){
			h=h&a[i];
		}
		cout<<h;
	}
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n-1;j++){
				h=a[i]&a[j];
			}
			maxx=max(maxx,h);
		}
		cout<<maxx;
	}
	else{
		h=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			h=h&a[i];
		}
		cout<<h;
	}
	return 0;
}