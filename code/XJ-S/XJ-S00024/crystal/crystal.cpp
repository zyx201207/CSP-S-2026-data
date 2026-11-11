#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],mm[10000001],an[10000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
	//	cout<<a[i];
		if(i>=2){
			mm[i]=a[i]-a[i-1];
		}
	}
	an[2]=mm[2];
	for(long long i=2;i<=n;i++){
		an[i]=an[i-1]+(i-1)*mm[i];
	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
	//	cout<<an[i]<<' ';
//	}
//	cout<<'\n';
	for(long long i=1;i<=n;i++){
		if(an[i]>m){
			cout<<i-1;
			return 0;
		}
	}
} 
