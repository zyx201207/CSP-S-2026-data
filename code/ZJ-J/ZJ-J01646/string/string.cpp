#include<bits/stdc++.h>
using namespace std;
int n;
long long a[20001],sum;
char b[20001];
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			d+=b[i];	
		}
	}
	int l=0,r=d.size()-1;
	while(l<=r){
		if(d[l]!=d[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}