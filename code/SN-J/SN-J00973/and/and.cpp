#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200008];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(n-i+1==m){
			cout<<a[i]<<endl;
			return 0;
		}
	}
	return 0;
}

