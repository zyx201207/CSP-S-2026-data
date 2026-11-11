#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[10000000];
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	cout<<c[a-1];
	return 0;
}
