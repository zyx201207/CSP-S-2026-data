#include<bits/stdc++.h>
using namespace std;
int n,m,num=0;
signed main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		num=a[0];
		for(int i=1;i<n;i++){
			num = num + a[i];
			cout << num;
		}
	}
	return 0;
}
