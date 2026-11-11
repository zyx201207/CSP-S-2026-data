#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,h=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int b=a[i] & a[j];
			h=max(h,b);
		}
	}
	cout<<h;
	return 0;
}
