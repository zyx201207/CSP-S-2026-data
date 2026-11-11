#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long int n,m;
int l;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int tmp=a[1]-a[0];
	unsigned long long int i=0;
	while(m>=tmp*(i+1)&&i<n){
		m-=tmp*(i+1);
		i++;
		tmp=a[i+1]-a[i];
	}
	cout<<min(i+1,n);
	return 0;
} 
