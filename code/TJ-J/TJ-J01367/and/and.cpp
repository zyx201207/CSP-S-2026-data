#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long l[n];
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	cout<<l[n-1];
	return 0;
}
