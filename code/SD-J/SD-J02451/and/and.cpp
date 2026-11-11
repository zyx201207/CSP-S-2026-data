#include<bits/stdc++.h>
using namespace std;
unsigned int a[1000005],dp[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	unsigned int r=0;
	for(int i=0;i<n-m;i++){
		unsigned int ar=0xFFFFFFFFu;
		for(int j=i;j<m+i;j++)ar=ar&a[j];
		r=max(r,ar);
	}
	cout<<r;
	fclose(stdin);fclose(stdout);
	return 0; 
}
