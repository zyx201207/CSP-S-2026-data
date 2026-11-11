#include<bits/stdc++.h>
using namespace std;
int a[4]={1,2,1,4};
int c[1000005];
int ans[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int b;
		cin>>b;
		c[i]=b;
		cout<<a[i%m]<<" ";
	}
	for(int i=0;i<n;i++){
		int t[1000005];
		for(int j=0;j<m;j++){
			t[c[i+j]]++;
			t[c[i+j]]%=2;
		}
		
	}
	return 0;
}
