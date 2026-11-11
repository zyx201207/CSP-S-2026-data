#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int erjin(int x){
	int res=0;
	while(x){
		res=res+x%2;
		x/=2;
	}
	return res;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int er[n];
	for(int i=0;i<n;i++)
	{
		er[i]=erjin(a[i]);
	}
	long long int ci=0;
	int ans;
	for(int i=1;i<=n+1-m;i++){
		for(int j=1;j<=i;j++){
			ci+=j;
		}
	}
	if(m==1){
		sort(a,a+n,cmp);
		cout<<a[0];
	}
	return 0;
}
