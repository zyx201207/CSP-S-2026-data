#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l[n];
	int ma=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ma=max(ma,x);
	}
	cout<<ma;
	



	return 0;
}

