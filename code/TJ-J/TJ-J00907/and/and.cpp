#include <bits/stdc++.h>
using namespace std;
int a[1000001],n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			if(a[i]==m){
				a[i]=a[i]-'0';
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
