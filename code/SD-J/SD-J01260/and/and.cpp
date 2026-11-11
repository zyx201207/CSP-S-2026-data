#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,greater<int>());
	int ans=0;
	for(int i=0;i<=n-m;i++){
		for(int j=i+1;j<i+m;j++){
			a[i]&=a[j];
		}
		if(a[i]>ans){
			ans=a[i];
		}
	}
	cout<<ans;
	return 0;
}
