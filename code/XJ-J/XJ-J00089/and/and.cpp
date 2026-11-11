#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a,b[10000000];
	cin>>n>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int c=b[3]&&b[4];
	cout<<c;
	return 0;
} 

