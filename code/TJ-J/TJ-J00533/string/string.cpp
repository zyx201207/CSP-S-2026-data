#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[10005]={};
	char c[10005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	sum/=2;
	cout<<sum;
	
	
	return 0;
}
