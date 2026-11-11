#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200010],maxx=-1,s=1,e=n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxx){
				maxx=a[i]&a[j];
			}
		}
	}
	cout<<maxx;
	return 0;
}