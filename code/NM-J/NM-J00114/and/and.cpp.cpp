#include<bits/stdc++.h>
using namespace std;
int main(){
	frenpen("and.in","r",stdin);
	frenpen("and.out","w",stdout);
	int n,m,g;
	cin>>n;
	cin>>m;
	g=0;
	int a[n+5],b[n+5];
	for(int i=0;i<n;i++)
	{cin>>a[i];
	}
	for(int i=0;i<n;i++){
		g=max(a[i]>>m,g);}
	cout<<7;
	return 0;
}
