#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int cnt=max(a[n-1],a[n-2])-a[n-1]^a[n-2];
	for (int i=n-1;i>=n-m;i--){
		cnt=max(cnt,a[i])-cnt^a[i];
	}
	cout<<cnt;
}
