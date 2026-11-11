#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			cout<<0;
			return 0; 
		}
	}
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=n-1;i>n-m-1;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

