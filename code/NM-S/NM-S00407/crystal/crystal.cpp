#include<bits/stdc++.h>
using namespace std;
int n,m,most=-10;
int a[1000100],b[10000000][10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=n;i>1;i--){
		for(int j=i-1;j>=1;j--){
			b[i][j]=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		int c=0,d=-1;
		for(int j=1;j<=n;j++){
		 	c+=b[i][j];
			if(c>=m) break;
			d++;

		}
		most=max(d,most);
	}
	cout<<most;
	return 0;
}
