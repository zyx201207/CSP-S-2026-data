#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans and a[i]);
		}
		cout<<ans;
	}else{
		cout<<a[n-m+1];
	}
	
}
