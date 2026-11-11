#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			maxx=a[i]&a[i-1];
		}
		cout<<maxx;
	}
	return 0;
} 
