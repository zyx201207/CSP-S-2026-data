#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			sum=sum&a[j];
		}
		if(sum>maxx){
			maxx=sum;
		}
	}
	cout<<maxx;
	return 0;
}
