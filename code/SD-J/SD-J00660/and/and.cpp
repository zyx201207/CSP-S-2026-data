#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long q[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int w=0;w<n;w++){
		cin>>q[w];
	}
	cout<<q[n-1];
	return 0;
}
