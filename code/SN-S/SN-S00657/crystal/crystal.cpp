#include<bits/stdc++.h>
using namespace std;
int a[10001],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x;
		sum+=x;
	}
	sum=sum/n;	
	cout<<sum;
}
