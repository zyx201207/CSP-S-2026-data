#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//·¢ÈÈopen
	int n,m;
	int a[100000];
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}
