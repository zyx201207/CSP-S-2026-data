#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int z[500000]={0};
	for(int i=0;i<a;i++) {
		cin>>z[i];
	}
	cout<<z[a-1]<<endl;
	return 0;
}
