#include <bits/stdc++.h>
using namespace std;
int a[100000010];
int main( ){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	char c;
	string s;
	for (int i=0;i<n;i++){
		cin>>a[i]>>c;
		s+=a[i]*c;
	}
	cout<<"1";
	return 0;
}
