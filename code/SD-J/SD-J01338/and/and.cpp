#include<bits/stdc++.h>
using namespace std;
int n,m;
void s(){
	cin>>n>>m;
	int a[n+10];
	int b[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i]-1) b[i]=a[i];
	}
	cout<<b[n-1];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	s();
	return 0;
} 
