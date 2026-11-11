#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n/2;i++){
		s += a[i];
	}
	cout<<s<<" ";
	cout<<a[0]<<" ";
	cout<<a[n-1] + a[n-2];
	return 0;
}
