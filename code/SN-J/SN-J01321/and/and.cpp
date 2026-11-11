#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	cout<<c[a-1];
	return 0;
} 
