#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000000000005],d=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c[i];
	} 
	sort(c,c+1); 
	for(long long i=0;i<a;i++){
		cout<<c[a/2];
	}
	return 0;
} 
