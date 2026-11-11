#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200020];
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int aa;
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=n;i>=2;i--){
		if(a[i]!=a[i-1] and a[i]!=0){
			cnt++;
		}
		if(cnt==m){
			cout<<a[i];
			return 0;
		}
	}
	cout<<(1 and a[n-m+1]);
	return 0;
} 
