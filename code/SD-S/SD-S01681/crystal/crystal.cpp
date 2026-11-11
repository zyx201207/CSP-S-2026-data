#include<bits/stdc++.h>
int a[10000];
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int num;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	n-=2;
	int i=3;
	while(n){
		cin>>a[i];
		if(a[i]-a[i-1]==a[2]-a[1]){
			i++;
			n--;
		}
		else
		cin>>a[i];
	}
	if(a[2]>a[1])
	num=a[2]-a[1];
	else
	num=a[1]-a[2];
	cout<<m/num;
	return 0;
} 
