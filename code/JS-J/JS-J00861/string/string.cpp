#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long cnt;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char c;
		cin>>a[i];
		cin>>c;
	}
	for(int i=0;i<n;i++){
		cnt+=a[i];
	}
	cout<<cnt/2;
	return 0;
}
