#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int count=0;
int rp(int a,int b){
	return a&b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[N];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int maxx=-1;
	for(int i=1;i<=n;i++){
		int x=0;
		while(k--){
			x=rp(a[i],a[i+1]);
		}if(x>=maxx){
			maxx=x;
		}
	}
	cout<<maxx;
	return 0;
}
