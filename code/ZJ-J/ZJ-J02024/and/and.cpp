#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int num[2*N+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	int ans=num[n];
	for(int i=n-m+1;i<n;i++){
		ans&=num[i];
	}
	int nm=num[n-1];
	for(int i=n-m;i<n-1;i++){
		nm&=num[i];
	}
	cout<<max(ans,nm);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
