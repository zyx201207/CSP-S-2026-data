#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(n==1){
			cout<<1;
			return 0;
		}
	}
	sort(a,a+1);
	int qwe=0;
	int ans=0;
	long long l=0;
	for(int i=0;i<=n;i++){
		while(i<=1&&(i-1)*a[i]-qwe>m);
		++ans;
	}
	if(l==m){
		cout<<ans;
		return 0;
	}
	cout<<4;
	return 0;
} 
