#include<bits/stdc++.h> 
using namespace std;
int a[20005];
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){

		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x=a[i]&a[j];
			maxn=max(maxn,x);
		}
	}
	cout<<maxn;
	
}
