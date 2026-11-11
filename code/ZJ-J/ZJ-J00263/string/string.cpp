#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char b[200005];
string s,ds;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			ds+=b[i];
		}
	}
	int f=s.size()/2;
	for(int i=0;i<f;i++){
		if(s[i]!=ds[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
