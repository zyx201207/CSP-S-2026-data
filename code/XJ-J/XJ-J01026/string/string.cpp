#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[101];
	char c[101];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
			sum=c[i];
		}
	}
	cout<<sum;
	return 0;
}