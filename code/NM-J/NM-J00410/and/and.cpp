#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int c[1000000];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int temp=0,tem=0;
		temp=c[i];
		if(temp>=c[i+1]){
			tem=c[i+1];
			c[i+1]=temp;
			temp=tem;
		}
	}
	cout<<c[n];

	return 0;
}