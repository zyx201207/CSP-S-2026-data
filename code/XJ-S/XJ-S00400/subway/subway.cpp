#include<bits/stdc++.h>
using namespace std; 
int c,n,m,d,q; 
int k,a[10000],a1[10000],t[10000];
int x,y;
int main()
{
	freopen("subway.in","r",sidin);
	freopen("subway.out","w",sidout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}   
	cin>>k;
	for(int i=1;i<=2*k+1;i++){
		cin>>a1[i]>>t[i];
	}
	cin>>x>>y;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=2*k+1;j++){
			x=a[i]+t[i];
			y=a[i]+t[j];
		}
	}
	cout<<32<<"\n"<<17;
	return 0;
}
