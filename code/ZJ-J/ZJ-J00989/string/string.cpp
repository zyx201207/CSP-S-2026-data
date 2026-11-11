#include<bits/stdc++.h>
using namespace std;
int n,a[400000];
char c[400000],s[1000000001];
long long x,t=1,sum=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(t=1;t<=a[i];t++){
			s[sum]=c[i];
			sum++;
		}
	}
	for(int i=1;i<=(sum-1)/2+1;i++){
		if(s[i]!=s[sum-i]){
			x++;
		}
	}
	cout<<x;
	return 0;
} 
