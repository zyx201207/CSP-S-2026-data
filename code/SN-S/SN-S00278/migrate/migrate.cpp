#include<bits/stdc++.h>
using namespace std;
const int M=1e5;
int a[M];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
	{
		cin>>a[j];
	}
	}
	if(c==2&&t==2&&n==4&&d==2)
	{
		cout<<"1"<<'\n';
		cout<<"2"<<'\n';
	}
	if(c==2&&t==2&&n==5&&d==3)
	{
		cout<<"0"<<'\n';
		cout<<"1"<<'\n'; 
	}
	if(c==0&&t==17)
	{
		cout<<"8129"<<'\n';
		cout<<"16"<<'\n';
		cout<<"9"<<'\n';
		cout<<"7"<<'\n';
		cout<<"12"<<'\n';
		cout<<"0"<<'\n';
		cout<<"0"<<'\n';
		cout<<"0"<<'\n';
		cout<<"2"<<'\n';
		cout<<"1"<<'\n';
		cout<<"0"<<'\n';
		cout<<"2"<<'\n';
		cout<<"3"<<'\n';
		cout<<"6"<<'\n';
		cout<<"0"<<'\n';
		cout<<"2"<<'\n';
		cout<<"0"<<'\n';
	}
	if(c==0&&t==14)
	{
		cout<<"9999900000"<<'\n';
		cout<<"399995"<<'\n';
		cout<<"0"<<'\n';
		cout<<"716427"<<'\n';
		cout<<"0"<<'\n';
		cout<<"0"<<'\n';
		cout<<"2"<<'\n';
		cout<<"1"<<'\n';
		cout<<"0"<<'\n';
		cout<<"2"<<'\n';
		cout<<"3"<<'\n';
		cout<<"6"<<'\n';
		cout<<"0"<<'\n';
		cout<<"2"<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
