#include<bits\stdc++.h>
using namespace std;
int a[500010],an=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,p=0,j=0,an=0;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<m/(a[n-1]-a[n-2]);
	return 0;
}
