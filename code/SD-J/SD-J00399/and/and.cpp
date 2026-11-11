#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}

