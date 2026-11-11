#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freeopen("string.in","r",stdin);
	freeopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	string zifu;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			zifu=zifu+b[i];
		}
	}
	for(int i=0,j=zifu.size();i<=zifu.size()/2,j>=zifu.size()/2,i=j;i++,j--){
		if(a[i]!=a[j]){
			a[j]=a[0];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
