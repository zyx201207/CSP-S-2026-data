#include<bits/stdc++.h>
using namespace std;
string a;
long long n,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long x;
		char y;
		cin>>x>>y;
		while(x--){
			a+=y;
		}
	}
	int k=0,l=0,r=a.size();
	while(l<=r){
		if(a[l]!=a[r]){
			k=0;
			sum++;
		}
		l++;
		r--;
	}
	if(k==1){
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
}
