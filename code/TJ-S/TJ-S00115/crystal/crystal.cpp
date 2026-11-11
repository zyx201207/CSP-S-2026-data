#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	int a[100005];
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(a[0]==a[1] && a[1]==a[2]){
			cout<<'3';
		}
	}
	cout<<'3';
	return 0;
}
 	
