#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005];
int qz[500005];
bool check(int l,int r){
	int num=a[r]*(r-l)-(qz[r-1]-qz[l-1]);
	if(num<=m) return 1;
	return 0;
}
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	qz[0]=a[0];
	for(int i=1;i<n;i++){
		qz[i]=qz[i-1]+a[i];
	}
	int l=0;
	for(int r=0;r<n;r++){
		while(check(l,r)==0){
			l++;
		}
		ans=max(ans,r-l+1);
	}	
	cout<<ans;
	return 0;
}
