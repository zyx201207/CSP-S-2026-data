#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	n=65536;
	for(int i=49152;i<65536;i++) n&=i;
	
	cout<<n;
	return 0;
}
