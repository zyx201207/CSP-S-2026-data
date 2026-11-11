#include<bits/stdc++.h>
using namespace std;
int a[500001]={},b[500001]={};
int main()
{
	freopen('and.in','r',stdin);
	freopen('and.out','w',stdout);
	int n,m,maxx=0,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int i=1;i<=n-m;i++){
		x=a[i];
		for(int j=i+1;j<=m;j++){
			x=x & a[j];
		}
		if(x>maxx) maxx=x;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
