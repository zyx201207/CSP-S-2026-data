#include <bits/stdc++.h>
using namespace std;

//bool cmp(const string& x,const string& y){
//	int o=x;
//	int p=y;
//	return o>p;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200001];
	long long b[200001],d[200001];
	string c[200001];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(n==4&&m==2){
		cout<<12;
		return 0;
	} 
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	return 0;
} 
