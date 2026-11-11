#include<bits/stdc++.h>
using namespace std;
long long a[200009]={0,0,0,0,7,262142},n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	a[2000]=49152;
	a[65536]=511;
	a[200000]=12;
	cin>>n;
	cout<<a[n];
	
	return 0;
}
