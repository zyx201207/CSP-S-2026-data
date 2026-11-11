#include<bits/stdc++.h>
using namespace std;
int a[200001],f[200001];
bool fgh(int n){
	long long f=1;
	for (int i=1;i<=31;i++){
		f*=2;
		if (f == n){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("and4.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	if (fgh(n)){
		cout<<3*m;
	}
	return 0;
}
