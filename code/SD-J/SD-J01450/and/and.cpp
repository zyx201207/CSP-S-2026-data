#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N];
int maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t=a[i]&a[j];
			maxx=max(maxx,t);
		}
	}
	cout<<maxx;
	return 0;
}
