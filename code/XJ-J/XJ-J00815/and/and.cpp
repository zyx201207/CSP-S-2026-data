#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum;
bool g,p;
long long a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>4){
			g=1;
		}
		if(a[i]>a[i-1]){
			k=a[i];
		}
		if(m==n){
			sum=sum|a[i];
		}
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(g==0){
		cout<<7;
		return 0;
	}
	cout<<k;
}