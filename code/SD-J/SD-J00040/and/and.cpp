#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin>>n>>m;
	int a[n+5],mx,m1[n+5];
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n-1;i++){
		m1[i]=max(a[i],a[i+1]);
	}
	for(int i=m-2;i<=0;i--){
		for(int j=0;j<=i-1;j++){
			m1[i]=max(m1[i],m1[i+1]);
		}
	}
	cout<<min(m1[0],m1[1]);
	return 0;
}
