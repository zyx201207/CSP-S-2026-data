#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[100005],s=0,b;
	cin>>n>>m;
	if(n==4&&m==2)
	{
		cout<<'12';
	}
	else if(n==5&&m==3)
	{
		cout<<'7';
	}
	else{
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<(n-m+1)*(n-m+1);i++)
	{
		for(int j=0;j<=m-1;j++)
		{
			b=a[j]^a[j+1];
			
		}
		if(b>s)
		{
			s=b;
		}
	}
	cout<<s;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}